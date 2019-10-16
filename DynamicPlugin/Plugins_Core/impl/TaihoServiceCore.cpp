#include "TaihoServiceCore.h"
#if QT_VERSION < 0x050000
#include <QtCore/QtPlugin>
#endif
#include <QFile>
#include <QTextStream>
#include <QDebug>
TaihoServiceCore::TaihoServiceCore()
{
    QFile file("./plugins/Plugins_Core.json");
    if(file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream in(&file);
        QString line = in.readAll();

        metaJsonData = neb::CJsonObject(line.toStdString());

    }else
    {
        qDebug()<<"Plugins_Core.json error ";
    }
}

neb::CJsonObject& TaihoServiceCore::GetMetaData()
{
    return metaJsonData;
}

void TaihoServiceCore::recMsgFromManager(TaihoPluginData data)
{
    qDebug()<<Q_FUNC_INFO<<" src "<<data.src<<" dst "<<data.dst;
}

void TaihoServiceCore::onPluginsDidLoaded()
{
    qDebug()<<Q_FUNC_INFO<<" Call";
}

void TaihoServiceCore::onPluginsWillUnLoad()
{
    qDebug()<<Q_FUNC_INFO<<" Call";
}



#if QT_VERSION < 0x050000
Q_EXPORT_PLUGIN2(Plugins_Core, TaihoServiceCore)
#endif
