#ifndef PLATFORMSYSTEM_H
#define PLATFORMSYSTEM_H

#include <QObject>
#include "interface/IPlatformSystem.h"
class PlatformSystem : public IPlatformSystem
{
    Q_OBJECT
#if QT_VERSION >= 0x050000
    Q_PLUGIN_METADATA(IID IPlatformSystem_iid)
#endif
    Q_INTERFACES(IPlatformSystem)

public:
    explicit PlatformSystem();
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

#endif // PLATFORMSYSTEM_H
