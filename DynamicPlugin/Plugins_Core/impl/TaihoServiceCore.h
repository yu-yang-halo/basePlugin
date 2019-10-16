#ifndef TAIHOSERVICECORE_H
#define TAIHOSERVICECORE_H

#include <QObject>
#include "interface/ITaihoServiceCore.h"
class TaihoServiceCore : public ITaohoServiceCore
{
    Q_OBJECT
#if QT_VERSION >= 0x050000
    Q_PLUGIN_METADATA(IID ITaihoServiceCore_iid)
#endif
    Q_INTERFACES(ITaohoServiceCore)

public:
    explicit TaihoServiceCore();
    virtual neb::CJsonObject  &GetMetaData();
    virtual void recMsgFromManager(TaihoPluginData data);
    virtual void onPluginsDidLoaded();
    virtual void onPluginsWillUnLoad();
signals:
    void sendMsgToManager(TaihoPluginData);
public slots:

private:
    neb::CJsonObject metaJsonData;

};

#endif // TAIHOSERVICECORE_H
