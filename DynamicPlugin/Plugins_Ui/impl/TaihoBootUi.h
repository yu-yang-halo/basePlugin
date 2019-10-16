#ifndef TAIHOBOOTUI_H
#define TAIHOBOOTUI_H

#include <QWidget>
#include "interface/TaihoPluginInterface.h"
namespace Ui {
class TaihoBootUi;
}

class TaihoBootUi : public QWidget,public TaihoPluginInterface
{
    Q_OBJECT
#if QT_VERSION >= 0x050000
    Q_PLUGIN_METADATA(IID ITaohoPluginInterface_iid)
#endif
    Q_INTERFACES(TaihoPluginInterface)

public:
    explicit TaihoBootUi(QWidget *parent = 0);
    ~TaihoBootUi();
    void timerEvent(QTimerEvent *);
    virtual neb::CJsonObject  &GetMetaData();
    virtual void recMsgFromManager(TaihoPluginData data);
    virtual void onPluginsDidLoaded();
    virtual void onPluginsWillUnLoad();
signals:
    void sendMsgToManager(TaihoPluginData);
public slots:

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();

private:
    neb::CJsonObject metaJsonData;
    
private:
    Ui::TaihoBootUi *ui;


};

#endif // TAIHOBOOTUI_H
