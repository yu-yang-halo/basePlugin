#ifndef TAIHOPLUGINAI_H
#define TAIHOPLUGINAI_H

#include <QWidget>
#include "interface/TaihoPluginInterface.h"
namespace Ui {
class TaihoPluginAI;
}

class TaihoPluginAI : public QWidget,public TaihoPluginInterface
{
    Q_OBJECT
#if QT_VERSION >= 0x050000
    Q_PLUGIN_METADATA(IID ITaohoPluginInterface_iid)
#endif
    Q_INTERFACES(TaihoPluginInterface)

public:
    explicit TaihoPluginAI(QWidget *parent = 0);
    ~TaihoPluginAI();
    virtual neb::CJsonObject  &GetMetaData();
    virtual void recMsgFromManager(TaihoPluginData data);
    virtual void onPluginsDidLoaded();
    virtual void onPluginsWillUnLoad();
signals:
    void sendMsgToManager(TaihoPluginData);
public slots:


private:
    neb::CJsonObject metaJsonData;
    
private:
    Ui::TaihoPluginAI *ui;
};

#endif // TAIHOPLUGINAI_H
