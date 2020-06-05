#include "bridge.h"
#include <QMessageBox>
#include <QJSEngine>
#include <QDebug>
#include "mainwindow.h"

bridge* bridge::instance()
{
    static bridge s_obj;
    return &s_obj;
}

bridge::bridge()
{
}

QList<Light_t> bridge::returnWayPointList()
{
//    AddLight();
    return m_lightList;
}

void bridge::newPoint(double lng, double lat)
{
    _fLng = lng;
    _fLat = lat;
}
void bridge::setNavPointRotate(int rot)
{
    emit rotateNavPoint(rot);
}

Light_t	bridge::AddLight(int rot)
{
	static int s_count = 1;
	Light_t tLight;
	tLight.strName = QString("Light%1").arg(s_count);
	tLight.strDesc = QString("Light Description %1").arg(s_count);
    tLight.fLng = _fLng;
    tLight.fLat = _fLat;
	tLight.nValue = 0;
    tLight.rotation = rot;
	m_lightList.append(tLight);	
	s_count++;
	return tLight;
}

QVariantList bridge::GetLightData()
{
	int nCount = m_lightList.count();
    qDebug()<<nCount;
	QVariantList markerList;
	
	for(int i=0; i<nCount; i++)
	{
		Light_t tLight = m_lightList[i];
		QVariantMap map;
		map.insert("name", 	tLight.strName);
		map.insert("description", 	tLight.strDesc);
        map.insert("point", 	QString("%1,%2,%3").arg(tLight.fLng, 0, 10, 10).arg(tLight.fLat, 0, 10, 10).arg(tLight.rotation));
		map.insert("value", 	tLight.nValue);
		markerList << map;
	}
	
	return markerList;
}


void bridge::onLightOn(QString strName)
{
	SetLightValue(strName, 1);
}

void bridge::onLightOff(QString strName)
{
	SetLightValue(strName, 0);
}

void bridge::jsSendMsg(const QString& msg)
{
    emit toRecvMsg(msg);
}

void bridge::jsSendTargetPoint(const QString &msg)
{
    emit targetPointReceived(msg);
}

void bridge::SetLightValue(QString strName, int nValue)
{
	int nCount = m_lightList.count();	
	for(int i=0; i<nCount; i++)
	{
		Light_t tLight = m_lightList[i];
		if( m_lightList[i].strName == strName)
		{
			m_lightList[i].nValue = nValue;
			break;
		}
	}
	emit sigLightStatus(strName, nValue);
}

void bridge::removeAllPoints()
{
    m_lightList.clear();
    emit removePoints();
}
void bridge::onUpdateData()
{
	emit sigUpdateLight();
}

