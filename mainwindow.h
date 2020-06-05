#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTime>
#include <QWebEngineView>
#include <QWebEnginePage>
#include <QWebChannel>
#include "server.h"
#include <QLabel>

#include <sys/stat.h>
#include <unistd.h>
#include <cstdio>

#include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/video/video.hpp>

#include "bridge.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
class Server;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    double   fLng;
    double	fLat;
    double direction; // the map_direct, comes from the Baidu Map route plan
    double manul_direction;

protected:
    void keyPressEvent(QKeyEvent *);
//    void keyReleaseEvent(QKeyEvent *);

private slots:
    void onTurnLeftButton();
    void onTurnRightButton();
    void onGoStraightButton();
    void on_pushButton_clicked();
    void timeCountsFunction();
    void callJava();
    void onBtnLightOn();
    void onBtnLightOff();
    void onBtnAddLight();
    void onGoButton();
    void onClearAllPoint();
    void onTimeOut();
    void onTakeoffButton();
    void onReleaseYawSlider();
//    void onReleaseThrottleSlider();
    void onReleasePitchSlider();
    void onReleaseRollSlider();
    void onReleaseThrottleSlider();
    void onEnableVirtualStickButton();
    void onDisableVirtualStickButton();
    void sendVirtualStickCommand();
    void onSetRoll();
    void onReleaseNavSlider();

private:
    Ui::MainWindow *ui;
    Ui::Server *server_;
    QDockWidget* dock_server_;

    QTimer* timer_1;
    QTimer* timer_2;
    void onRecvdMsg(const QString msg);
    void onRecvTargetPoint(const QString msg);
    QTimer m_timer;
    QTimer* virtualStickTimer;
    void InitForm();
    bridge *bridgeins;
    void sendWayPoint();

    void InitVirtualStickControl();
    QTcpServer tcpServer_for_python_controller;
    QTcpSocket *tcpSocket_for_python_controller;

    void acceptConnection_for_python_controller();
    void updateCommand_from_python_controller();

private slots:
    void readFarme();       // 读取当前帧信息
    void closeCamara();     // 关闭摄像头。

    void on_detect_carButton_clicked();
//    void paintEvent(QPaintEvent *event);
    void on_track_carButton_clicked();

    void on_do_nothing_clicked();

private:
    QTimer    *timer;
    QImage    *imag;
    cv::VideoCapture cam;
    cv::Mat  frame;

    int rollBias = 0, pitchBias = 0, yawBias = 0, throttleBias = 0;
};

#endif // MAINWINDOW_H
