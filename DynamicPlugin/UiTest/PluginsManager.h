#ifndef PLUGINSMANAGER_H
#define PLUGINSMANAGER_H

#include <QObject>
#include <QPluginLoader>
#include <QHash>
#include <QVariant>
#include <QStringList>
#include "interface/TaihoPluginInterface.h"
class PluginsManagerPrivate;
class PluginsManager : public QObject
{
    Q_OBJECT
public:
    explicit PluginsManager(QObject *parent = 0);
    ~PluginsManager();
    static PluginsManager *instance();

    void setPluginsPath(QString pluginsPath);

    bool isCircleDepends(QStringList &circleDependList,QStringList &libQueuePaths);

    //加载所有插件
    void loadAllPlugins();
    //扫描JSON文件中的插件元数据
    void scanMetaData(const QString &filepath);
    //加载其中某个插件
    void loadPlugin(const QString &filepath);
    //卸载所有插件
    void unloadAllPlugins();
    //卸载某个插件
    void unloadPlugin(const QString &filepath);
    //获取所有插件
    QList<QPluginLoader *> allPlugins();
    //获取某个插件
    QPluginLoader* getPlugin(const QString &name);
private:
    PluginsManagerPrivate *d;
    QString m_pluginsPath;
    QStringList m_libQueuePaths;
signals:
    void publishPluginMsg(TaihoPluginData data);
public slots:
    void recMsgfromPlugin(TaihoPluginData data);

};

class PluginsManagerPrivate
{
public:
    //插件依赖检测
    bool check(const QString &filepath);

    QMap<QString, QVariant> m_names; //插件路径--插件名称
    QMap<QString, QVariant> m_versions; //插件路径--插件版本
    QMap<QString, QVariantList> m_dependencies; //插件路径--插件额外依赖的其他插件
    QMap<QString, QPluginLoader *>m_loaders; //插件路径--QPluginLoader实例
};

#endif // PLUGINSMANAGER_H
