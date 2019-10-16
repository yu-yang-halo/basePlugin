#ifndef TAIHOPLUGININTERFACE_H
#define TAIHOPLUGININTERFACE_H
#include <QObject>
#include <QMap>
#include <QVariant>
#include <QString>

#include "json/CJsonObject.hpp"

/**
 * 插件通信消息封装体
 **/
struct TaihoPluginData
{
    QString src;
    QString dst;
    int type;
    QMap<QString,QVariant> dataMap;
    QMap<QString,QObject *> objectMap;
};
Q_DECLARE_METATYPE(TaihoPluginData)

class TaihoPluginInterface
{
public:
    virtual ~TaihoPluginInterface(){}
    virtual neb::CJsonObject&  GetMetaData() = 0;
    virtual void recMsgFromManager(TaihoPluginData data) = 0;
    virtual void sendMsgToManager(TaihoPluginData data)   = 0;
    virtual void onPluginsDidLoaded() = 0;
    virtual void onPluginsWillUnLoad() = 0;

};

#define ITaohoPluginInterface_iid "com.taiho.core.TaihoPluginInterface"   // 唯一标识符

Q_DECLARE_INTERFACE(TaihoPluginInterface,ITaohoPluginInterface_iid)

#endif // TAIHOPLUGININTERFACE_H
