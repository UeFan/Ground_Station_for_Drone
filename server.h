#ifndef SERVER_H
#define SERVER_H


#include <QAbstractSocket>
#include <QTcpServer>
#include <QScrollBar>
#include <QMessageBox>

#include <QJsonDocument>
#include <QJsonObject>

#include <QtWidgets>
#include <QtNetwork>
#include <QList>

class QTcpSocket;

namespace Ui{
class MainWindow;

class Server : public QWidget
{
public:
    Server(QWidget* parent);
    QJsonObject json, jsonGPS, jsonGimbal, jsonBattery;
    void sendMessage(QString infomation);

private:

    QTcpServer tcpServer_for_receive, tcpServer_for_send;
    QTcpSocket *tcpServerConnection_for_receive, *tcpServerConnection_for_send;
    QList<QTcpSocket*> *socket_list;

    qint64 totalBytes;     // 存放总大小信息
    QString fileName;      // 存放文件名
    QByteArray inBlock;    // 数据缓冲区
    QScrollBar *scrollbar;

    QTextEdit *textEdit;
    QJsonObject getJsonObjectFromString(const QString jsonString);

    QCheckBox *ifHostIp;
    QLineEdit *setIpAddress;
    QPushButton* save_log_button; // which actually is the "listen" button

    QList<QHostAddress> ipList;

//    void responseToCheckBox();
    void startListening();
    void updateServerProgress();
    void acceptConnection_for_receive();
    void acceptConnection_for_send();
    void clear();

  //  void displayError(QAbstractSocket::SocketError socketError);
};

} //namespace Ui
#endif // SERVER_H
