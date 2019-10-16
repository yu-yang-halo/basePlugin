#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(&manager,SIGNAL(publishPluginMsg(TaihoPluginData)),this,SLOT(recivePluginMsg(TaihoPluginData)));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::recivePluginMsg(TaihoPluginData data)
{
    if(data.type == 0)
    {

        QVariant dependPlugins = data.dataMap.value("plugins");
        qDebug()<<" ============== "<<dependPlugins.toString();

        QPluginLoader *loader = manager.getPlugin(data.src);

        if(loader)
        {
            TaihoPluginInterface* interface = dynamic_cast<TaihoPluginInterface*>(loader->instance());
            data.objectMap.clear();
            QStringList strList = dependPlugins.toString().split(",");

            for(int i=0;i<strList.size();i++)
            {
                data.objectMap.insert(strList.at(i),manager.getPlugin(strList.at(i)));
            }

            if(interface)
            {
                interface->recMsgFromManager(data);
            }else
            {
                qDebug()<<Q_FUNC_INFO<<"plugin "<<data.dst<<" is illegal";
            }
        }

    }
}

void MainWindow::on_pushButton_clicked()
{
    manager.loadAllPlugins();
}


void MainWindow::on_pushButton_2_clicked()
{
    QPluginLoader *loader = manager.getPlugin("Plugins_Mode");
    if(loader)
    {
        TaihoPluginInterface* sys = dynamic_cast<TaihoPluginInterface*>(loader->instance());
        if(sys)
        {
            ui->textBrowser->setText(QString::fromStdString(sys->GetMetaData().ToFormattedString()));
        }
    }
}

void MainWindow::on_pushButton_3_clicked()
{
    QPluginLoader *loader = manager.getPlugin("Plugins_Ui");
    if(loader)
    {
        QObject* sys = dynamic_cast<QObject*>(loader->instance());
        if(sys->isWidgetType())
        {
            QWidget* widget = dynamic_cast<QWidget*>(loader->instance());
            widget->show();

            TaihoPluginInterface* sys = dynamic_cast<TaihoPluginInterface*>(loader->instance());
            if(sys)
            {
                ui->textBrowser->setText(QString::fromStdString(sys->GetMetaData().ToFormattedString()));
            }
        }

    }
}

void MainWindow::on_pushButton_4_clicked()
{
    QPluginLoader *loader = manager.getPlugin("Plugins_AI");
    if(loader)
    {
        QObject* sys = dynamic_cast<QObject*>(loader->instance());
        if(sys->isWidgetType())
        {
            QWidget* widget = dynamic_cast<QWidget*>(loader->instance());
            widget->show();

            TaihoPluginInterface* sys = dynamic_cast<TaihoPluginInterface*>(loader->instance());
            if(sys)
            {
                ui->textBrowser->setText(QString::fromStdString(sys->GetMetaData().ToFormattedString()));
            }
        }

    }
}

void MainWindow::on_pushButton_5_clicked()
{
    QPluginLoader *loader = manager.getPlugin("Plugins_Core");
    if(loader)
    {
        TaihoPluginInterface* sys = dynamic_cast<TaihoPluginInterface*>(loader->instance());
        if(sys)
        {
            ui->textBrowser->setText(QString::fromStdString(sys->GetMetaData().ToFormattedString()));
        }
    }
}

void MainWindow::on_pushButton_6_clicked()
{
    manager.unloadAllPlugins();
}


