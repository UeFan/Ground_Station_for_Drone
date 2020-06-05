#include "server.h"
#include "bridge.h"

namespace Ui {


Server::Server(QWidget* parent)
{
    setWindowFlags(Qt::Window);
    setWindowTitle("Log");
    resize(320, 640);

    QGridLayout* grid = new QGridLayout(this);
        grid->setContentsMargins(5, 10, 5, 5);

        QHBoxLayout* upper_button_layout = new QHBoxLayout();

        setIpAddress = new QLineEdit();
        upper_button_layout->addWidget(setIpAddress);

//        ifHostIp = new QCheckBox(tr("Host IP"),this); //check box button is useless
//        upper_button_layout->addWidget(ifHostIp);
//        connect(ifHostIp, &QCheckBox::stateChanged, this, &Server::responseToCheckBox);

        /******To get possible host ip address******/
        ipList = QNetworkInterface::allAddresses();
        foreach (QHostAddress address, ipList)
        {
               if(address.protocol() == QAbstractSocket::IPv4Protocol) //我们使用IPv4地址
                qDebug() <<"IP Address: "<<address.toString();
//                setIpAddress->setText(QString::fromStdString(address.toString()));
        }


        QHBoxLayout* lower_button_layout = new QHBoxLayout();

        save_log_button = new QPushButton(tr("listen"), this);
        connect(save_log_button, &QPushButton::released, this, &Server::startListening);
        lower_button_layout->addWidget(save_log_button);

        QPushButton* clear_button = new QPushButton(tr("Clear"), this);
        connect(clear_button, &QPushButton::released, this, &Server::clear);
        lower_button_layout->addWidget(clear_button);

        grid->addLayout(lower_button_layout, 1, 0, Qt::AlignLeft);

        grid->addLayout(upper_button_layout, 0, 0, Qt::AlignLeft);

        textEdit = new QTextEdit(this);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setReadOnly(true);
        grid->addWidget(textEdit, 2, 0, 1, 2);


        tcpServerConnection_for_receive = new QTcpSocket(this);
        tcpServerConnection_for_send = new QTcpSocket(this);
        socket_list = new QList<QTcpSocket*>;
        connect(&tcpServer_for_receive, &QTcpServer::newConnection,
                this, &Server::acceptConnection_for_receive);
        connect(&tcpServer_for_send, &QTcpServer::newConnection,
                this, &Server::acceptConnection_for_send);
    totalBytes = 0;

}

void Server::startListening()
{
    //   if (!tcpServer.listen(QHostAddress::LocalHost, 6666)) {
     if (!tcpServer_for_receive.isListening() && !tcpServer_for_receive.listen(QHostAddress::Any, 6666))  //QHostAddress::Any = 4 	双any-address栈，与该地址绑定的socket将侦听IPv4和IPv6接口。
     {
           qDebug() <<"error_in_sever_for_receive"<< tcpServer_for_receive.errorString();
           close();
           return;
     }
     if(tcpServer_for_receive.isListening())
     {
         save_log_button->setEnabled(false);
         qDebug() <<"=============start listening==========";
     }
     if (!tcpServer_for_send.isListening() && !tcpServer_for_send.listen(QHostAddress::Any, 6665))  //QHostAddress::Any = 4 	双any-address栈，与该地址绑定的socket将侦听IPv4和IPv6接口。
     {
           qDebug() <<"error_in_sever_for_send"<< tcpServer_for_send.errorString();
           close();
           return;
     }
     if(tcpServer_for_send.isListening())
     {
         qDebug() <<"=============ok for send==========";
     }
}

void Server::acceptConnection_for_receive()
{
    tcpServerConnection_for_receive = tcpServer_for_receive.nextPendingConnection();
    connect(tcpServerConnection_for_receive, &QTcpSocket::readyRead,
            this, &Server::updateServerProgress);
//    connect(tcpServerConnection, SIGNAL(error(QAbstractSocket::SocketError)),
//            this, SLOT(displayError(QAbstractSocket::SocketError)));
  //  ui->serverStatusLabel->setText(tr("接受连接"));
  //  关闭服务器，不再进行监听
  //  tcpServer.close();
}
void Server::acceptConnection_for_send()
{
    tcpServerConnection_for_send = tcpServer_for_send.nextPendingConnection();
    socket_list->append(tcpServerConnection_for_send);
    qDebug() <<"============== found send target=========";
}

void Server::clear(){
    textEdit->clear();
}

//void Server::responseToCheckBox()
//{
//    if(ifHostIp->checkState() == Qt ::Unchecked)
//    {
//        setIpAddress->clear();
//        setIpAddress->setEnabled(true);
//    }
//    else
//    {
//        setIpAddress->setText(tr("127.0.0.1"));
//        setIpAddress->setEnabled(false);
//    }


//}




void Server::updateServerProgress()
{
    QDateTime time = QDateTime::currentDateTime();
    QString str = time.toString("\n[ hh:mm:ss ]"); //设置显示格式
    //qDebug()<<str;

    qint64 len = tcpServerConnection_for_receive->bytesAvailable();
    //qDebug()<<"socket data len:"<< len;
    QByteArray alldata = tcpServerConnection_for_receive->read(len);
    //开始转换编码
    QTextCodec *utf8codec = QTextCodec::codecForName("UTF-8");
    QString utf8str = utf8codec->toUnicode(alldata.mid(2));
    //qDebug()<<"hex:["<<alldata.toHex().toUpper()<<"]";
//    qDebug()<<"utf-8 ["<< (utf8str) << "]";


    json = getJsonObjectFromString(utf8str);

    if(json.contains("GPS")){
        jsonGPS = json["GPS"].toObject();
//        qDebug()<<"\n->"<< jsonGPS["altitude"].toDouble();
    }

    if(json.contains("Gimbal")){
        jsonGimbal = json["Gimbal"].toObject();
    }
    if(json.contains("Battery0")){
        jsonBattery = json["Battery0"].toObject();
    }

    //显示到控件上
    textEdit->insertPlainText(str);//在标签上显示时间
    textEdit->insertPlainText(utf8str);
    textEdit->insertPlainText(tr("\n"));


    //自动滚动到最底
    scrollbar = textEdit->verticalScrollBar();
    if (scrollbar)
    {
       scrollbar->setSliderPosition(scrollbar->maximum());
    }
//    QString ser = "test,test,test,test,test,test\n";
//    sendMessage(ser);
}

//void Server::displayError(QAbstractSocket::SocketError socketError)
//{
//    qDebug() << tcpServerConnection->errorString();
//    tcpServerConnection->close();
//    //ui->serverProgressBar->reset();
//    //ui->serverStatusLabel->setText(tr("服务端就绪"));

//}


void Server::sendMessage(QString infomation)
{
    QByteArray message = infomation.toLocal8Bit();
//    QDataStream out(&message, QIODevice::WriteOnly);
//    out.setVersion(QDataStream::Qt_DefaultCompiledVersion);
//    out<<infomation.toLocal8Bit();
    //qDebug()<<message;
    for(int i = 0; i<socket_list->length(); i++)
    {
        socket_list->at(i)->write(message);
    }
}

QJsonObject Server::getJsonObjectFromString(const QString jsonString){
    QJsonDocument jsonDocument = QJsonDocument::fromJson(jsonString.toLocal8Bit().data());
    if( jsonDocument.isNull() ){
        qDebug()<< "===> please check the string "<< jsonString.toLocal8Bit().data();
    }
    QJsonObject jsonObject = jsonDocument.object();
    return jsonObject;
}

} //namespce Ui
