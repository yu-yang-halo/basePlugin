#include "TaihoBootUi.h"
#include "ui_TaihoBootUi.h"
#if QT_VERSION < 0x050000
#include <QtCore/QtPlugin>
#endif
#include <QFile>
#include <QTextStream>
#include <QDebug>
TaihoBootUi::TaihoBootUi(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TaihoBootUi)
{
    ui->setupUi(this);
    QFile file("./plugins/Plugins_Ui.json");
    if(file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream in(&file);
        QString line = in.readAll();

        metaJsonData = neb::CJsonObject(line.toStdString());

    }else
    {
        qDebug()<<"Plugins_Ui.json error ";
    }

    startTimer(1000);


}
neb::CJsonObject& TaihoBootUi::GetMetaData()
{

    return metaJsonData;
}

void TaihoBootUi::recMsgFromManager(TaihoPluginData data)
{
    if(data.type == 0)
    {
        if(data.objectMap.size() > 0)
        {
            QObject* pluginCore = data.objectMap.value("Plugins_Core");
            QObject* pluginMode = data.objectMap.value("Plugins_Mode");

            qDebug()<<Q_FUNC_INFO<<" pluginCore "<<pluginCore<<" pluginMode "<<pluginMode;
        }
    }
}

void TaihoBootUi::onPluginsDidLoaded()
{
    qDebug()<<Q_FUNC_INFO<<" CALL ";

    TaihoPluginData data;
    data.src = "Plugins_Ui";
    data.dst = "";
    data.type = 0;
    data.dataMap.insert("plugins","Plugins_Core,Plugins_Mode");
    emit sendMsgToManager(data);
}

void TaihoBootUi::onPluginsWillUnLoad()
{
    qDebug()<<Q_FUNC_INFO<<" CALL ";
}


TaihoBootUi::~TaihoBootUi()
{
    delete ui;
}

void TaihoBootUi::timerEvent(QTimerEvent *)
{
    qDebug()<<".TaihoBootUi........";
}


#if QT_VERSION < 0x050000
Q_EXPORT_PLUGIN2(Plugins_Ui, TaihoBootUi)
#endif

void TaihoBootUi::on_pushButton_clicked()
{
    TaihoPluginData data;
    data.src = "Plugins_Ui";
    data.dst = "Plugins_Core";
    data.type = 99;
    data.dataMap.insert("msg","send msg to plugin core");
    emit sendMsgToManager(data);
}

void TaihoBootUi::on_pushButton_2_clicked()
{
    TaihoPluginData data;
    data.src = "Plugins_Ui";
    data.dst = "Plugins_Mode";
    data.type = 89;
    data.dataMap.insert("msg","send msg to plugin mode");
    emit sendMsgToManager(data);
}
