#ifndef ITAIHOSERVICECORE_H
#define ITAIHOSERVICECORE_H
#include <QObject>
#include "TaihoPluginInterface.h"
/**
 * @brief The ITaohoServiceCore class
 * 平台系统接口  插件化接口
 */
class ITaohoServiceCore :public QObject, public TaihoPluginInterface
{
    Q_OBJECT
    Q_INTERFACES(TaihoPluginInterface)
public:
    virtual ~ITaohoServiceCore(){}
    virtual neb::CJsonObject&  GetMetaData() = 0;
    virtual void recMsgFromManager(TaihoPluginData data) = 0;
    virtual void sendMsgToManager(TaihoPluginData data)   = 0;
    virtual void onPluginsDidLoaded() = 0;
    virtual void onPluginsWillUnLoad() = 0;

};


#define ITaihoServiceCore_iid "com.taiho.core.ITaohoServiceCore"   // 唯一标识符

Q_DECLARE_INTERFACE(ITaohoServiceCore,ITaihoServiceCore_iid)
#endif // ITAIHOSERVICECORE_H
