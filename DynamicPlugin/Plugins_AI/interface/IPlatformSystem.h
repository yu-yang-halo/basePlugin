#ifndef IPLATFORM_H
#define IPLATFORM_H

#include <QObject>
#include "TaihoPluginInterface.h"
/**
 * @brief The IPlatformSystem class
 * 平台系统接口  插件化接口
 */
class IPlatformSystem : public QObject,public TaihoPluginInterface
{
    Q_OBJECT
    Q_INTERFACES(TaihoPluginInterface)
public:
    virtual ~IPlatformSystem(){}
    virtual neb::CJsonObject&  GetMetaData() = 0;
    virtual void recMsgFromManager(TaihoPluginData data) = 0;
    virtual void sendMsgToManager(TaihoPluginData data)   = 0;
    virtual void onPluginsDidLoaded() = 0;
    virtual void onPluginsWillUnLoad() = 0;

};


#define IPlatformSystem_iid "com.taiho.core.IPlatformSystem"   // 唯一标识符

Q_DECLARE_INTERFACE(IPlatformSystem,IPlatformSystem_iid)

#endif // IPLATFORM_H   
