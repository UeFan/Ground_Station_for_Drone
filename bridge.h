#ifndef BRIDGE_H
#define BRIDGE_H

#include <QObject>
#include <QJSValue>
#include <functional>
#include <QVariant>
#include <QString>
#include <QJsonArray>
#include <QJsonObject>
#include <QVariantList>


typedef struct
{
	QString strName;
	QString strDesc;
    double   fLng;
    double	fLat;
	int		nValue;
    int rotation;
}Light_t;

class bridge : public QObject
{
Q_OBJECT
public:
    static bridge* instance();
private:
    bridge();
    double _fLng = 0, _fLat = 0;
	QList<Light_t> m_lightList;
	void SetLightValue(QString strName, int nValue);
signals:
    void sigUpdateLight();
    void removePoints();
	void sigLightStatus(const QString& strName, int nvalue);
    void toRecvMsg(const QString& msg); //收到数据
    void targetPointReceived(const QString& msg);
    void rotateNavPoint(int rot);
public slots:
    void onLightOn(QString strName);
	void onLightOff(QString strName);
	void onUpdateData();
    void jsSendMsg(const QString& msg);     // 接收到页面发送来的消息
    void jsSendTargetPoint(const QString& msg);
	QVariantList	GetLightData();
public:
    QList<Light_t>	returnWayPointList();
    Light_t			AddLight(int rot);
	const QList<Light_t>& GetLightList(){return m_lightList;}
    void newPoint(double lng, double lat);
    void removeAllPoints();
    void setNavPointRotate(int rot);

};

#endif // BRIDGE_H
