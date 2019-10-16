#include "PlatformSystem.h"
#if QT_VERSION < 0x050000
#include <QtCore/QtPlugin>
#endif
#include <QFile>
#include <QTextStream>
#include <QDebug>
PlatformSystem::PlatformSystem()
{
    QFile file("./plugins/Plugins_Mode.json");
    if(file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream in(&file);
        QString line = in.readAll();

        metaJsonData = neb::CJsonObject(line.toStdString());

    }else
    {
        qDebug()<<"Plugins_Mode.json error ";
    }
}

neb::CJsonObject& PlatformSystem::GetMetaData()
{
    return metaJsonData;
}

void PlatformSystem::recMsgFromManager(TaihoPluginData data)
{
    qDebug()<<Q_FUNC_INFO<<" src "<<data.src<<" dst "<<data.dst<<" type "<<data.type;
}

void PlatformSystem::onPluginsDidLoaded()
{
    qDebug()<<Q_FUNC_INFO<<" Call ";
}

void PlatformSystem::onPluginsWillUnLoad()
{
    qDebug()<<Q_FUNC_INFO<<" Call ";
}



#if QT_VERSION < 0x050000
Q_EXPORT_PLUGIN2(Plugins_Mode, PlatformSystem)
#endif
