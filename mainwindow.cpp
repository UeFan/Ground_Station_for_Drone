#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>
#include <math.h>

#include<cv.h>
#include<opencv2/opencv.hpp>

#include <QCoreApplication>
#include <Python.h>

class MySlider : public QSlider {
public:
  explicit MySlider(QWidget *parent = 0);

protected:
  void mousePressEvent(QMouseEvent *event) {
    //获取点击触发前的值
    const int value = this->value();
    //调用父类的鼠标点击处理事件
    QSlider::mousePressEvent(event);
    setValue(value);
    //向父窗口发送自定义事件event type，这样就可以在父窗口中捕获这个事件进行处理
    QEvent evEvent(static_cast<QEvent::Type>(QEvent::User + 1));
    QCoreApplication::sendEvent(parentWidget(), &evEvent);
  }
};


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    InitForm();
    InitVirtualStickControl();
    server_ = new Ui::Server(this);
    dock_server_ = new QDockWidget("Info", this);
    dock_server_->setWidget(server_);
    addDockWidget(Qt::LeftDockWidgetArea, dock_server_);
    //dock_server_->setFloating(1);
    manul_direction = 0;
    cam = cv::VideoCapture(1);//从摄像头中获取视频(1), get images from the drone's cam:(0), get images from a video file:("/home/wwh/1.18.m4v")
    if(!cam.isOpened())
        std::cerr << "Can't open camera!" <<std::endl;;

    timer = new QTimer(this);
    timer->start(50);              // 开始计时，超时则发出timeout()信号

    ui->zoomSlider->setMaximum(1000);
    ui->zoomSlider->setMinimum(0);
    ui->zoomSlider->setValue(1000);
    ui->navPointSlider->setMaximum(365);
    ui->navPointSlider->setMinimum(0);
    ui->navPointSlider->setValue(0);
    connect(timer, SIGNAL(timeout()), this, SLOT(readFarme()));  // 时间到，读取当前摄像头信息


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::InitForm()
{
    QWebChannel *channel = new QWebChannel(this);
    bridgeins = bridge::instance();
    channel->registerObject("bridge", (QObject*)bridgeins);
    ui->webView->page()->setWebChannel(channel);
    ui->webView->page()->load(QUrl::fromLocalFile(qApp->applicationDirPath() + "/bin/index.html"));


    const QList<Light_t>& list = bridgeins->GetLightList();
    int nCount = list.count();
    for(int i=0; i<nCount; i++)
    {
        Light_t tLight = list[i];
        ui->cbLight->addItem(tLight.strDesc, tLight.strName);
    }
    ui->cbLight->setCurrentIndex(0);

    ui->lineEditLat->setMinimumWidth(10);
    ui->lineEditLng->setMinimumWidth(10);

    connect(ui->turnLeftButton,SIGNAL(clicked()), this, SLOT(onTurnLeftButton()));
    connect(ui->turnRightButton,SIGNAL(clicked()), this, SLOT(onTurnRightButton()));
    connect(ui->goStraightButton,SIGNAL(clicked()), this, SLOT(onGoStraightButton()));


    connect(ui->btnAdd, SIGNAL(clicked()), this, SLOT(onBtnAddLight()));
//    connect(ui->btnLightOn, SIGNAL(clicked()), this, SLOT(onBtnLightOn()));
//    connect(ui->btnLightOff, SIGNAL(clicked()), this, SLOT(onBtnLightOff()));
    connect(ui->takeoffButton, SIGNAL(clicked()), this, SLOT(onTakeoffButton()));
    connect(ui->goButton, SIGNAL(clicked()), this, SLOT(onGoButton()));
    connect(ui->clearAllPointButton, SIGNAL(clicked()), this, SLOT(onClearAllPoint()));

    connect(&m_timer, SIGNAL(timeout()), this, SLOT(onTimeOut()));

    connect(bridgeins, &bridge::toRecvMsg, this, &MainWindow::onRecvdMsg);
    m_timer.start(500);


    //this->showMaximized();
}

void MainWindow::keyPressEvent(QKeyEvent *e)
{
    switch(e->key())
    {
    case Qt::Key_W : throttleBias++; ui->throttleSlider->setValue(ui->throttleSlider->value()+throttleBias);ui->throttleBiasLabel->setText(QString::number(throttleBias)); break;
    case Qt::Key_S : throttleBias--; ui->throttleSlider->setValue(ui->throttleSlider->value()+throttleBias);ui->throttleBiasLabel->setText(QString::number(throttleBias)); break;
    case Qt::Key_A : yawBias--; ui->yawBiasLabel->setText(QString::number(yawBias));break;
    case Qt::Key_D : yawBias++; ui->yawBiasLabel->setText(QString::number(yawBias));break;
    case Qt::Key_I : rollBias++; ui->rollBiasLabel->setText(QString::number(rollBias));break;
    case Qt::Key_K : rollBias--; ui->rollBiasLabel->setText(QString::number(rollBias));break;
    case Qt::Key_J : pitchBias--; ui->pitchBiasLabel->setText(QString::number(pitchBias));break;
    case Qt::Key_L : pitchBias++; ui->pitchBiasLabel->setText(QString::number(pitchBias)); break;
    default : break;
    }
}

void MainWindow::InitVirtualStickControl()
{
    tcpSocket_for_python_controller = new QTcpSocket(this);
    connect(ui->enableVirtualStickButton, SIGNAL(clicked()), this, SLOT(onEnableVirtualStickButton()));
    connect(ui->disableVirtualStickButton, SIGNAL(clicked()), this, SLOT(onDisableVirtualStickButton()));
    connect(ui->setRollButton, SIGNAL(clicked()), this, SLOT(onSetRoll()));
    virtualStickTimer = new QTimer(this);
    ui->disableVirtualStickButton->setEnabled(false);

    ui->yawSlider->setMaximum(1000);
    ui->yawSlider->setMinimum(-1000);
    ui->yawSlider->setValue(0);

    ui->pitchSlider->setMaximum(1000);
    ui->pitchSlider->setMinimum(-1000);
    ui->pitchSlider->setValue(0);

    ui->rollSlider->setMaximum(1000);
    ui->rollSlider->setMinimum(-1000);
    ui->rollSlider->setValue(0);

    ui->throttleSlider->setMaximum(1000);
    ui->throttleSlider->setMinimum(-1000);
    ui->throttleSlider->setValue(0);

    connect(ui->yawSlider, SIGNAL(sliderReleased()), this, SLOT(onReleaseYawSlider()));
    connect(ui->pitchSlider, SIGNAL(sliderReleased()), this, SLOT(onReleasePitchSlider()));
    connect(ui->rollSlider, SIGNAL(sliderReleased()), this, SLOT(onReleaseRollSlider()));
    connect(ui->throttleSlider, SIGNAL(sliderReleased()), this, SLOT(onReleaseThrottleSlider()));

    connect(ui->navPointSlider, SIGNAL(sliderMoved(int)), this, SLOT(onReleaseNavSlider()));
    if(!tcpServer_for_python_controller.isListening() && !tcpServer_for_python_controller.listen(QHostAddress::LocalHost, 5555))
    {
          qDebug() <<"error_in_sever_for_receive"<< tcpServer_for_python_controller.errorString();
          close();
          return;
    }
    if(tcpServer_for_python_controller.isListening())
    {
        qDebug()<<"=============start listening to python controller==========";
    }
    connect(&tcpServer_for_python_controller, &QTcpServer::newConnection, this, &MainWindow::acceptConnection_for_python_controller);

}


void MainWindow::sendVirtualStickCommand()
{
    QJsonObject jsonToSend_0;
    jsonToSend_0.insert("mission", 2);            //takeoff = 0, waypoint = 1, virtual stick = 2, disable virtual stick = 3
    jsonToSend_0.insert("yaw", double(ui->yawSlider->value())/1000);
    jsonToSend_0.insert("roll", double(ui->rollSlider->value())/1000);
    jsonToSend_0.insert("pitch", double(ui->pitchSlider->value())/1000);
    jsonToSend_0.insert("throttle", double(ui->throttleSlider->value())/1000);

    QString str = QString(QJsonDocument(jsonToSend_0).toJson());
//    qDebug()<<str;
    server_->sendMessage(str);
}
void MainWindow::onTurnLeftButton()
{
    manul_direction = 300;
}
void MainWindow::onTurnRightButton()
{
    manul_direction = 60;
}
void MainWindow::onGoStraightButton()
{
    manul_direction = 0;
}

void MainWindow::onReleaseNavSlider()
{
    bridgeins->setNavPointRotate(int(ui->navPointSlider->value()));
}

void MainWindow::onDisableVirtualStickButton()
{
    disconnect(virtualStickTimer, SIGNAL(timeout()),0,0);
    virtualStickTimer->stop();
    ui->yawSlider->setValue(0);
    ui->pitchSlider->setValue(0);
    ui->rollSlider->setValue(0);

//    QJsonObject jsonToSend_0;
//    jsonToSend_0.insert("mission", 2);            //takeoff = 0, waypoint = 1, virtual stick = 2, disable virtual stick = 3
//    jsonToSend_0.insert("yaw", ui->yawSlider->value()/1000);
//    jsonToSend_0.insert("roll", ui->rollSlider->value()/1000);
//    jsonToSend_0.insert("pitch", ui->pitchSlider->value()/1000);
//    jsonToSend_0.insert("throttle", double(ui->throttleSlider->value())/1000);

//    QString str = QString(QJsonDocument(jsonToSend_0).toJson());
//    qDebug()<<str;
//    server_->sendMessage(str);

    QJsonObject jsonToSend_1;
    jsonToSend_1.insert("mission", 3);
    jsonToSend_1.insert("yaw", ui->yawSlider->value()/1000);
    jsonToSend_1.insert("roll", ui->rollSlider->value()/1000);
    jsonToSend_1.insert("pitch", ui->pitchSlider->value()/1000);
    jsonToSend_1.insert("throttle", double(ui->throttleSlider->value())/1000);

    QString str  = QString(QJsonDocument(jsonToSend_1).toJson());
//    qDebug()<<str;
    server_->sendMessage(str);

    ui->enableVirtualStickButton->setEnabled(true);
    ui->disableVirtualStickButton->setEnabled(false);
}

void MainWindow::onEnableVirtualStickButton()
{
    ui->enableVirtualStickButton->setEnabled(false);
    ui->disableVirtualStickButton->setEnabled(true);
    virtualStickTimer->start(100);
    connect(virtualStickTimer, SIGNAL(timeout()), this, SLOT(sendVirtualStickCommand()));
}

void MainWindow::updateCommand_from_python_controller()
{
    qint64 len = tcpSocket_for_python_controller->bytesAvailable();

    QByteArray alldate = tcpSocket_for_python_controller->read(len);
    QTextCodec *utf8codec = QTextCodec::codecForName("UTF-8");
    QString utf8str = utf8codec->toUnicode(alldate.mid(2));
    //qDebug()<<"pthon_controller:"<<utf8str<<"\n";
    QStringList control_command = utf8str.split(",");
    ui->yawSlider->setValue(control_command.at(0).toDouble() + yawBias);
    ui->pitchSlider->setValue(control_command.at(1).toDouble() + pitchBias);
//    qDebug()<<"yaw:"<<control_command.at(0).toDouble()<<"\n";
    ui->yawLabel->setText(control_command.at(0));
    ui->pitchLabel->setText(control_command.at(1));

    ui->rollSlider->setValue(control_command.at(2).toDouble() + rollBias);
    ui->rollLabel->setText(control_command.at(2));

    // send the map_direct to python controller
    if(direction>180||direction<-180)
        direction = 0;
    if(ui->manulDirectCheckBox->isChecked())
    {
        direction = manul_direction;
    }

    if((direction>=0 && direction<30) || (direction>330 && direction<=360))
        ui->turnLabel->setText(tr("Go straight"));
    if((direction>=30 && direction<=90))
        ui->turnLabel->setText(tr("Turn right"));
    if((direction>=270 && direction<=330))
        ui->turnLabel->setText(tr("Turn left"));
    QString sWriteData = QString::number(direction);
    tcpSocket_for_python_controller->write(sWriteData.toUtf8());
}

void MainWindow::onRecvTargetPoint(const QString msg)
{
    QStringList lst;
    lst = msg.split(',');
    double next_point_direction = 0;
    QString targetNum = lst[0];
    int targetRotation = lst[1].toInt();
//    bridgeins->onLightOn(targetNum);
    double targetLng = lst[2].toDouble();
    double targetLat = lst[3].toDouble();
    int arrayListLength = lst[4].toInt();
    //qDebug()<<fixed<<qSetRealNumberPrecision(7)<<targetLng<<" "<<targetLat;
    //qDebug()<<(ui->lineEditLng->text().toDouble()+0.0126)<<" "<<(ui->lineEditLat->text().toDouble()+0.0062);
//    qDebug()<<((targetLng - (ui->lineEditLng->text().toDouble()+0.0125))/(targetLat - (ui->lineEditLat->text().toDouble()+0.0062);
    // first quadrant
    if((targetLng - (ui->lineEditLng->text().toDouble()+0.0126))>0 && (targetLat - (ui->lineEditLat->text().toDouble()+0.0062))>0)
        next_point_direction = atan2((targetLng - (ui->lineEditLng->text().toDouble()+0.0126)), (targetLat - (ui->lineEditLat->text().toDouble()+0.0062)))*180/3.14159;
    // second quadrant
    if((targetLng - (ui->lineEditLng->text().toDouble()+0.0126))<0 && (targetLat - (ui->lineEditLat->text().toDouble()+0.0062))>0)
        next_point_direction = 360 + atan2((targetLng - (ui->lineEditLng->text().toDouble()+0.0126)), (targetLat - (ui->lineEditLat->text().toDouble()+0.0062)))*180/3.14159;
    // third quadrant
    if((targetLng - (ui->lineEditLng->text().toDouble()+0.0126))<0 && (targetLat - (ui->lineEditLat->text().toDouble()+0.0062))<0)
        next_point_direction = 360 + atan2((targetLng - (ui->lineEditLng->text().toDouble()+0.0125)), (targetLat - (ui->lineEditLat->text().toDouble()+0.0062)))*180/3.14159;
    // forth quadrant
    if((targetLng - (ui->lineEditLng->text().toDouble()+0.0126))>0 && (targetLat - (ui->lineEditLat->text().toDouble()+0.0062))<0)
        next_point_direction = atan2((targetLng - (ui->lineEditLng->text().toDouble()+0.0125)), (targetLat - (ui->lineEditLat->text().toDouble()+0.0062)))*180/3.14159;

    next_point_direction = (double)targetRotation;
    qDebug()<<next_point_direction<<":"<<targetNum<<","<<arrayListLength;//server_->jsonGPS["yaw"].toDouble();
    direction = next_point_direction - server_->jsonGPS["yaw"].toDouble();
    if(direction>180)
        direction = direction - 360;
    else if(direction<-180)
        direction = 360 + direction;

    if(targetNum == QString("-1"))
        direction = 0;
}

void MainWindow::acceptConnection_for_python_controller()
{
    qDebug()<<"acceptConnection_for_python_controller";
    tcpSocket_for_python_controller = tcpServer_for_python_controller.nextPendingConnection();
    connect(bridgeins, &bridge::targetPointReceived, this, &MainWindow::onRecvTargetPoint);
    connect(tcpSocket_for_python_controller, &QTcpSocket::readyRead, this, &MainWindow::updateCommand_from_python_controller);
}

void MainWindow::onReleaseYawSlider()
{
    ui->yawSlider->setValue(0);
}

void MainWindow::onSetRoll()
{
    ui->rollSlider->setValue(65);
    ui->rollLabel->setText(tr("65"));
}

void MainWindow::onReleasePitchSlider()
{
    ui->pitchSlider->setValue(0);
}

void MainWindow::onReleaseRollSlider()
{
    ui->rollSlider->setValue(0);
}

void MainWindow::onReleaseThrottleSlider()
{
    ui->throttleSlider->setValue(0);
}

void MainWindow::onRecvdMsg(QString msg)
{
    qDebug()<<QString("Received message：%1").arg(msg);
    QStringList lst;
    lst = msg.split(',');
    qDebug()<<lst;
    fLng = lst[0].toDouble();
    fLat = lst[1].toDouble();
    qDebug()<<fixed<<qSetRealNumberPrecision(7)<<fLng<<" "<<fLat;
    bridgeins->newPoint(fLng,fLat);
}

void MainWindow::sendWayPoint()
{
    QList<Light_t> wayPointList = bridgeins->returnWayPointList();
    QJsonObject jsonToSend;
    jsonToSend.insert("mission", 1);            //takeoff = 0, waypoint = 1
    jsonToSend.insert("altitude", ui->waypointAlt->text().toDouble());
    jsonToSend.insert("way_point_num", wayPointList.size());
    for(int i = 0; i<wayPointList.size(); i++)
    {
        jsonToSend.insert(QString::number(i)+"Lng", wayPointList.at(i).fLng - 0.0126);
        jsonToSend.insert(QString::number(i)+"Lat", wayPointList.at(i).fLat - 0.0062);
    }
    QString str = QString(QJsonDocument(jsonToSend).toJson());
    //qDebug()<<str;
    server_->sendMessage(str);
}


void MainWindow::onTakeoffButton()
{
    QJsonObject jsonToSend;
    jsonToSend.insert("mission", 0);
    QString str = QString(QJsonDocument(jsonToSend).toJson());
    qDebug()<<str;
    server_->sendMessage(str);
}

void MainWindow::onClearAllPoint()
{
    if(ui->cbLight->count()>=1)
    {
        ui->cbLight->clear();
        bridgeins->removeAllPoints();
    }
}

void MainWindow::onGoButton()
{
    sendWayPoint();
}
void MainWindow::onBtnAddLight()
{
    Light_t tLight = bridgeins->AddLight(int(ui->navPointSlider->value()));
    ui->cbLight->addItem(tLight.strDesc, tLight.strName);
    ui->cbLight->setCurrentIndex(ui->cbLight->count()-1);
    bridgeins->onUpdateData();
}

void MainWindow::onBtnLightOn()
{
    QString strName = ui->cbLight->currentData().toString();
    bridgeins->onLightOn(strName);
}

void MainWindow::onBtnLightOff()
{
    QString strName = ui->cbLight->currentData().toString();
    bridgeins->onLightOff(strName);
}

void MainWindow::onTimeOut()
{
//	bridgeins->onUpdateStatus();
}
void MainWindow::timeCountsFunction()
{
    ui->lineEditLng->setText(QString::number(server_->jsonGPS["longitude"].toDouble(), 10, 8));
    //qDebug() <<"\n->"<< server_->jsonGPS["altitude"].toString();
    ui->lineEditLat->setText(QString::number(server_->jsonGPS["latitude"].toDouble(), 10, 8));
    ui->Alt->setText(QString::number(server_->jsonGPS["altitude"].toDouble()));

    ui->VelH->setText(QString::number(sqrt(pow(server_->jsonGPS["velocityY"].toDouble(),2)+pow(server_->jsonGPS["velocityX"].toDouble(), 2))));
    ui->VelV->setText(QString::number(server_->jsonGPS["velocityZ"].toDouble()));

    ui->Bat->setText(QString::number(server_->jsonBattery["BatteryEnergyRemainingPercent"].toDouble()));
}


void MainWindow::on_pushButton_clicked()
{
    timer_1 = new QTimer(this);
    timer_1->start(100);

    timer_2 = new QTimer(this);
    timer_2->start(200);

    bridgeins->setNavPointRotate(int(ui->navPointSlider->value()));

    connect(timer_1,SIGNAL(timeout()),this,SLOT(timeCountsFunction())); // disable if you want to test the map point.
    connect(timer_2,SIGNAL(timeout()),this,SLOT(callJava()));
}

void MainWindow::callJava()
{
    QString strJs_ = "myFunction(%1, %2, ";
    strJs_ += QString::number(server_->jsonGPS["yaw"].toDouble(), 10, 1);
      //strJs_ += QString::number(10.5, 10, 1);
    strJs_ += ")";
//    QString strJs = strJs_
//            .arg(ui->lineEditLng->text().toDouble()*0.01+109.03525)
//            .arg(ui->lineEditLat->text().toDouble()*0.01+26.6564);
    QString strJs = strJs_
            .arg(ui->lineEditLng->text().toDouble()+0.0126,0,10,8)
            .arg(ui->lineEditLat->text().toDouble()+0.0062,0,10,8);
    ui->webView->page()->runJavaScript(strJs);
    //qDebug()<<strJs;
}

/*********************************
********* 读取摄像头信息 ***********
**********************************/

void MainWindow::readFarme()
{

    char* pic_tmp_path = "/home/wwh/rpg_public_dronet-master/tmp.jpg";
    char* pic_path = "/home/wwh/rpg_public_dronet-master/cam.jpg";
    cam >> frame;// 从摄像头中抓取并返回每一帧
    double radio = (double)ui->zoomSlider->value()/1000;
    frame(cv::Rect(int((1-radio)/2*frame.size().width),int((1-radio)/2*frame.size().height),int(radio*frame.size().width),int(radio*frame.size().height))).copyTo(frame);
//    cv::rectangle(frame,cvPoint(20,200),cvPoint(200,300),cvScalar(255,0,0),1,1,0);
     //将抓取到的帧，转换为QImage格式。QImage::Format_RGB888不同的摄像头用不同的格式。
    QImage image = QImage(frame.data, frame.cols, frame.rows, static_cast<int>(frame.step), QImage::Format_RGB888).rgbSwapped().scaled(640,360,Qt::KeepAspectRatioByExpanding);
    ui->label_3->setPixmap(QPixmap::fromImage(image));  // 将图片显示到label上
    cv::imwrite(pic_tmp_path,frame);
    if(access(pic_path,F_OK))
    {
        remove(pic_path);
    }
    rename(pic_tmp_path, pic_path);

//    cv::Mat frame = cv::imread( "/home/wwh/Desktop/0.jpg",1);//读入一站图片 暂时读入桌面上的一个文件
//    //cv::cvtColor(frame,frame,CV_BGR2RGB);//opencv读取图片按照BGR方式读取，为了正常显示，所以将BGR转为RGB
//     QImage image = QImage(frame.data, frame.cols, frame.rows, static_cast<int>(frame.step), QImage::Format_RGB888).rgbSwapped().scaled(640,320,Qt::KeepAspectRatioByExpanding);
////     cv::waitKey(100);
//    ui->label_3->setPixmap(QPixmap::fromImage(image)); //将图片显示在QLabel上


//    ui->deepImg->setPixmap(QPixmap("/home/wwh/2.jpg").scaled(320,160));

    QFile my_file("/home/wwh/Desktop/number.txt");//将QFile与相关文件关联
   if(!my_file.open(QIODevice::ReadOnly | QIODevice::Text))//以只读和文本模式打开文件
   {
       qDebug() <<"Could not open file for Reading";
       return;
   }
   QTextStream outText(&my_file);  //将QTextStream与特定文件关联
   QString number = outText.readAll();  //读出QTextStream对象中所有内容
   my_file.close(); //关闭文件
   ui->lineEditnumber->setText(number);
}



/*******************************
***关闭摄像头，释放资源，必须释放***
********************************/
void MainWindow::closeCamara()
{
    timer->stop();         // 停止读取数据。
    cam.release();//释放内存；
}

void MainWindow::on_detect_carButton_clicked()
{

    QFile my_file("/home/wwh/Desktop/detect_track.txt");//将QFile与相关文件关联
   if(!my_file.open(QIODevice::WriteOnly | QIODevice::Text))//以只读和文本模式打开文件
   {
       qDebug() <<"Could not open file for Writing";
       return;
   }
   QString str = "detect";
   QTextStream in(&my_file);
   in << str << "\n";
   my_file.close(); //关闭文件
}

void MainWindow::on_track_carButton_clicked()
{
    QFile my_file("/home/wwh/Desktop/detect_track.txt");//将QFile与相关文件关联
   if(!my_file.open(QIODevice::WriteOnly | QIODevice::Text))//以只读和文本模式打开文件
   {
       qDebug() <<"Could not open file for Writing";
       return;
   }
   QString str = "track";
   QTextStream in(&my_file);
   in << str << "\n";
   my_file.close(); //关闭文件
}

void MainWindow::on_do_nothing_clicked()
{
    QFile my_file("/home/wwh/Desktop/detect_track.txt");//将QFile与相关文件关联
   if(!my_file.open(QIODevice::WriteOnly | QIODevice::Text))//以只读和文本模式打开文件
   {
       qDebug() <<"Could not open file for Writing";
       return;
   }
   QString str = "wait";
   QTextStream in(&my_file);
   in << str << "\n";
   my_file.close(); //关闭文件
}
