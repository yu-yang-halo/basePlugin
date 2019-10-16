#include "TaihoPluginAI.h"
#include "ui_TaihoPluginAI.h"
#if QT_VERSION < 0x050000
#include <QtCore/QtPlugin>
#endif
#include <QFile>
#include <QTextStream>
#include <QDebug>
TaihoPluginAI::TaihoPluginAI(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TaihoPluginAI)
{
    ui->setupUi(this);
    QFile file("./plugins/Plugins_AI.json");
    if(file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream in(&file);
        QString line = in.readAll();

        metaJsonData = neb::CJsonObject(line.toStdString());

    }else
    {
        qDebug()<<"Plugins_AI.json error ";
    }
}
neb::CJsonObject& TaihoPluginAI::GetMetaData()
{

    return metaJsonData;
}

void TaihoPluginAI::recMsgFromManager(TaihoPluginData data)
{
    qDebug()<<Q_FUNC_INFO<<" src "<<data.src<<" dst "<<data.dst<<" type "<<data.type;
}

void TaihoPluginAI::onPluginsDidLoaded()
{
    qDebug()<<Q_FUNC_INFO<<" Call ";
}

void TaihoPluginAI::onPluginsWillUnLoad()
{
    qDebug()<<Q_FUNC_INFO<<" Call ";
}


TaihoPluginAI::~TaihoPluginAI()
{
    delete ui;
}


#if QT_VERSION < 0x050000
Q_EXPORT_PLUGIN2(Plugins_AI, TaihoPluginAI)
#endif

