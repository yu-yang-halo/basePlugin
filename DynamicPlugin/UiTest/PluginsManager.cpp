#include "PluginsManager.h"
#include <QDir>
#include <QFileInfoList>
#include <QFileInfo>
#include <QApplication>
#include <QDebug>
#include "json/CJsonObject.hpp"
struct Node
{
    QString name;
    Node* next;
};
static PluginsManager *m_instance = NULL;
PluginsManager::PluginsManager(QObject *parent) :
    QObject(parent)
{
    m_instance = this;
    d = new PluginsManagerPrivate;
    m_pluginsPath = "plugins";
}

PluginsManager::~PluginsManager()
{
    delete d;
    d = NULL;
}

PluginsManager *PluginsManager::instance()
{
    return m_instance;
}

void PluginsManager::setPluginsPath(QString pluginsPath)
{
    m_pluginsPath = pluginsPath;
}

bool PluginsManager::isCircleDepends(QStringList &circleDependList, QStringList &libQueuePaths)
{
    circleDependList.clear();
    libQueuePaths.clear();

    QDir pluginsdir = QDir(qApp->applicationDirPath());
    pluginsdir.cd(m_pluginsPath);
    QFileInfoList pluginsInfo = pluginsdir.entryInfoList(QDir::Files | QDir::NoDotAndDotDot);


    /**插件的路径映射表**/
    QMap<QString,QString> pluginsPathMap;
    /**插件的依赖映射表**/
    QMap<QString,QStringList> pluginsDependMap;
     /**插件的顺序映射表**/
    QMap<QString,int> pluginsOrderMap;

    for(int i=0;i<pluginsInfo.size();i++)
    {
        QFileInfo fileinfo = pluginsInfo.at(i);
        QString filepath = fileinfo.absoluteFilePath();
        if(!QLibrary::isLibrary(filepath))
            continue;
        QPluginLoader *loader = new QPluginLoader(filepath);
        if(loader->load())
        {
            TaihoPluginInterface *plugin = dynamic_cast<TaihoPluginInterface *>(loader->instance());
            if(plugin)
            {
                neb::CJsonObject metaDataJson = plugin->GetMetaData();

                std::string name_std_str;
                metaDataJson.Get("name",name_std_str);

                QString name = QString::fromStdString(name_std_str);

                neb::CJsonObject listJson = metaDataJson["dependencies"];

                QStringList strList;
                if(listJson.GetArraySize() > 0)
                {

                    for(int i=0;i<listJson.GetArraySize();i++)
                    {
                        std::string name_std_str;
                        listJson[i].Get("name",name_std_str);
                        QString name = QString::fromStdString(name_std_str);
                        strList.append(name);
                    }
                }
                pluginsDependMap.insert(name,strList);
                pluginsOrderMap.insert(name,0);
                pluginsPathMap.insert(name,filepath);

            }
        }
        loader->unload();
        delete loader;
        loader = NULL;
    }
    QList<QString> list = pluginsDependMap.keys();
    int size = list.size();
    int runCount = 0;
    while(true)
    {
        int count = 0;
        for(int i=0;i<size;i++)
        {
            QString key = list[i];
            QStringList strList = pluginsDependMap.value(key);
            int value = pluginsOrderMap.value(key);

            bool fit = true;
            for(int j=0;j<strList.size();j++)
            {
                int tmp =  pluginsOrderMap.value(strList[j]);
                if(value <= tmp)
                {
                    value = tmp+1;
                    fit = false;
                    if(runCount > size)
                    {
                        if(!circleDependList.contains(key))
                        {
                            circleDependList.append(key);
                        }
                    }
                }
            }
            pluginsOrderMap[key] = value;
            if(fit)
            {
              count++;
            }
        }

        if(size == count)
        {
            break;
        }
        runCount++;

        if(runCount > size*2)
        {
            qDebug()<<"Error may be circle depends";
            break;
        }
    }



    if(circleDependList.size() > 0)
    {
        qDebug()<<"pluginsOrderMap "<<pluginsOrderMap<<" circleDependList（循环依赖） "<<circleDependList
                <<" runCount "<<runCount;

        return true;
    }

    QStringList nameList = pluginsOrderMap.keys();

    for(int i=0;i<nameList.size();i++)
    {
        for(int j=i+1;j<nameList.size();j++)
        {
             int vi = pluginsOrderMap.value(nameList[i]);
             int vj = pluginsOrderMap.value(nameList[j]);

             if(vi > vj)
             {
                 QString tmp = nameList[i];
                 nameList[i] = nameList[j];
                 nameList[j] = tmp;
             }

        }
    }
    for(int i=0;i<nameList.size();i++)
    {
        libQueuePaths.append(pluginsPathMap.value(nameList[i]));
    }

    //qDebug()<<"nameList "<<nameList;
    //qDebug()<<"libQueuePaths "<<libQueuePaths;

    return false;
}

void PluginsManager::loadAllPlugins()
{
    QStringList circleDependList;

    if(isCircleDepends(circleDependList,m_libQueuePaths))
    {
        return;
    }
    //初始化插件中的元数据
    for(int i=0;i<m_libQueuePaths.size();i++)
    {
        QString filePath = m_libQueuePaths.at(i);
        scanMetaData(filePath);
    }

    unloadAllPlugins();

    //加载插件
    for(int i=0;i<m_libQueuePaths.size();i++)
    {
        QString filePath = m_libQueuePaths.at(i);
        loadPlugin(filePath);
    }
}

void PluginsManager::scanMetaData(const QString &filepath)
{
    //判断是否为库（后缀有效性）
    if(!QLibrary::isLibrary(filepath))
        return ;
    //获取元数据
    QPluginLoader *loader = new QPluginLoader(filepath);
    if(loader->load())
    {
        TaihoPluginInterface *plugin = dynamic_cast<TaihoPluginInterface *>(loader->instance());

        if(plugin != NULL)
        {
            neb::CJsonObject metaDataJson = plugin->GetMetaData();

            std::string name_std_str,version_std_str;
            metaDataJson.Get("name",name_std_str);
            metaDataJson.Get("version",version_std_str);

            QVariant name = QString::fromStdString(name_std_str);
            QVariant version = QString::fromStdString(version_std_str);

            QVariantList dependencies;
            neb::CJsonObject listJson = metaDataJson["dependencies"];
            if(listJson.GetArraySize() > 0)
            {
                for(int i=0;i<listJson.GetArraySize();i++)
                {
                    QVariantMap val;

                    std::string name_std_str,version_std_str;

                    listJson[i].Get("name",name_std_str);
                    listJson[i].Get("version",version_std_str);

                    QVariant name = QString::fromStdString(name_std_str);
                    QVariant version = QString::fromStdString(version_std_str);


                    val.insert("name",name);
                    val.insert("version",version);
                    dependencies.push_back(val);
                }
            }

            d->m_names.insert(filepath, name);
            d->m_versions.insert(filepath, version);
            d->m_dependencies.insert(filepath,dependencies);
        }else
        {
            qDebug()<<"plugin is illegal";
        }

    }
    loader->unload();
    delete loader;
    loader = NULL;
}

void PluginsManager::loadPlugin(const QString &filepath)
{
    if(!QLibrary::isLibrary(filepath))
        return;

    //检测依赖
    if(!d->check(filepath))
        return;

    //先卸载插件再加载
    unloadPlugin(filepath);
    //加载插件
    QPluginLoader *loader = new QPluginLoader(filepath);
    if(loader->load())
    {
        TaihoPluginInterface *plugin = dynamic_cast<TaihoPluginInterface *>(loader->instance());
        if(plugin)
        {
            // 每个插件发送消息到manager，然后由manager 根据 dest 字段转发
            connect(loader->instance(),SIGNAL(sendMsgToManager(TaihoPluginData)),this,SLOT(recMsgfromPlugin(TaihoPluginData)));
            d->m_loaders.insert(filepath, loader);
            plugin->onPluginsDidLoaded();
        }
        else
        {
            loader->unload();
            delete loader;
            loader = NULL;
        }
    }
}

void PluginsManager::unloadAllPlugins()
{
    for(int i = m_libQueuePaths.size() - 1;i>=0;i--)
    {
        QString path = m_libQueuePaths.at(i);
        unloadPlugin(path);
    }
}

void PluginsManager::unloadPlugin(const QString &filepath)
{
    QPluginLoader *loader = d->m_loaders.value(filepath);
    //卸载插件，并从内部数据结构中移除
    if(loader)
    {
        TaihoPluginInterface *plugin = dynamic_cast<TaihoPluginInterface *>(loader->instance());
        plugin->onPluginsWillUnLoad();

        bool result = loader->unload();
        if(result)
        {
            d->m_loaders.remove(filepath);
            delete loader;
            loader = NULL;
        }else
        {
            qDebug()<<"Error unload result "<<result<<" "<<filepath<<" loader->isLoaded() "<<loader->isLoaded();
        }
    }
}

QList<QPluginLoader *> PluginsManager::allPlugins()
{
    return d->m_loaders.values();
}


QPluginLoader *PluginsManager::getPlugin(const QString &name)
{
    QPluginLoader *loader = d->m_loaders.value(d->m_names.key(name));
    if(loader == NULL)
    {
        qDebug()<<Q_FUNC_INFO<<" plugins "<<name<<"  no exists ";
    }
    return  loader;
}

void PluginsManager::recMsgfromPlugin(TaihoPluginData data)
{
    emit publishPluginMsg(data);

}

bool PluginsManagerPrivate::check(const QString &filepath)
{
    for(int i=0;i<m_dependencies.value(filepath).size();i++)
    {

        QVariant item = m_dependencies.value(filepath).at(i);

        QVariantMap map = item.toMap();
        //依赖的插件名称、版本、路径
        QVariant name = map.value("name");
        QVariant version = map.value("version");
        QString path = m_names.key(name);

        /********** 检测插件是否依赖于其他插件 **********/
        // 先检测插件名称
        if(!m_names.values().contains(name))
        {
            QString strcons = "Missing dependency: "+ name.toString()+" for plugin "+path;
            qDebug()<<Q_FUNC_INFO<<strcons;
            return false;
        }
        //再检测插件版本
        if(m_versions.value(path) != version)
        {
            QString strcons = "Version mismatch: " + name.toString() +" version "+m_versions.value(m_names.key(name)).toString()+
                    " but " + version.toString() + " required for plugin "+path;
            qDebug()<<Q_FUNC_INFO<<strcons;
            return false;
        }
        //最后检测被依赖的插件是否还依赖其他的插件
        if(!check(path))
        {
            QString strcons = "Corrupted dependency: "+name.toString()+" for plugin "+path;
            qDebug()<<Q_FUNC_INFO<<strcons;

            return false;
        }
    }

    return true;
}

