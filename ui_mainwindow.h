/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qwebengineview.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_3;
    QHBoxLayout *horizontalLayout_9;
    QGroupBox *groupBox_5;
    QGroupBox *groupBox_4;
    QPushButton *enableVirtualStickButton;
    QSlider *yawSlider;
    QSlider *pitchSlider;
    QSlider *rollSlider;
    QLabel *yawLabel;
    QLabel *rollLabel;
    QPushButton *onRestStickValueButton;
    QLabel *pitchLabel;
    QPushButton *disableVirtualStickButton;
    QSlider *throttleSlider;
    QLabel *throttleLabel;
    QPushButton *setRollButton;
    QLabel *yawBiasLabel;
    QLabel *pitchBiasLabel;
    QLabel *throttleBiasLabel;
    QLabel *rollBiasLabel;
    QSlider *zoomSlider;
    QLabel *label_7;
    QPushButton *goStraightButton;
    QPushButton *turnLeftButton;
    QPushButton *turnRightButton;
    QLabel *turnLabel;
    QCheckBox *manulDirectCheckBox;
    QSlider *navPointSlider;
    QLabel *label_9;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout;
    QWebEngineView *webView;
    QHBoxLayout *horizontalLayout_5;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_8;
    QLabel *VelV;
    QLabel *label_12;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_6;
    QLabel *VelH;
    QLabel *label_14;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_10;
    QLabel *Bat;
    QLabel *label_13;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;
    QLabel *label;
    QLineEdit *lineEditLat;
    QLabel *label_2;
    QLineEdit *lineEditLng;
    QLabel *label_4;
    QLabel *Alt;
    QGroupBox *groupBox1;
    QHBoxLayout *horizontalLayout_7;
    QComboBox *cbLight;
    QPushButton *btnAdd;
    QPushButton *clearAllPointButton;
    QPushButton *takeoffButton;
    QLineEdit *waypointAlt;
    QPushButton *goButton;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *detect_carButton;
    QPushButton *track_carButton;
    QPushButton *do_nothing;
    QLabel *label_5;
    QLineEdit *lineEditnumber;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1116, 688);
        MainWindow->setMinimumSize(QSize(0, 0));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout_3 = new QHBoxLayout(centralWidget);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setMinimumSize(QSize(640, 320));
        label_3->setBaseSize(QSize(0, 0));
        label_3->setLineWidth(1);

        verticalLayout_2->addWidget(label_3);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        groupBox_5 = new QGroupBox(centralWidget);
        groupBox_5->setObjectName(QStringLiteral("groupBox_5"));
        groupBox_4 = new QGroupBox(groupBox_5);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        groupBox_4->setGeometry(QRect(0, 0, 316, 301));
        enableVirtualStickButton = new QPushButton(groupBox_4);
        enableVirtualStickButton->setObjectName(QStringLiteral("enableVirtualStickButton"));
        enableVirtualStickButton->setGeometry(QRect(10, 30, 141, 25));
        yawSlider = new QSlider(groupBox_4);
        yawSlider->setObjectName(QStringLiteral("yawSlider"));
        yawSlider->setGeometry(QRect(10, 100, 121, 16));
        yawSlider->setOrientation(Qt::Horizontal);
        pitchSlider = new QSlider(groupBox_4);
        pitchSlider->setObjectName(QStringLiteral("pitchSlider"));
        pitchSlider->setGeometry(QRect(169, 100, 131, 20));
        pitchSlider->setOrientation(Qt::Horizontal);
        rollSlider = new QSlider(groupBox_4);
        rollSlider->setObjectName(QStringLiteral("rollSlider"));
        rollSlider->setGeometry(QRect(210, 130, 16, 121));
        rollSlider->setOrientation(Qt::Vertical);
        yawLabel = new QLabel(groupBox_4);
        yawLabel->setObjectName(QStringLiteral("yawLabel"));
        yawLabel->setGeometry(QRect(20, 80, 67, 17));
        rollLabel = new QLabel(groupBox_4);
        rollLabel->setObjectName(QStringLiteral("rollLabel"));
        rollLabel->setGeometry(QRect(230, 170, 31, 16));
        onRestStickValueButton = new QPushButton(groupBox_4);
        onRestStickValueButton->setObjectName(QStringLiteral("onRestStickValueButton"));
        onRestStickValueButton->setGeometry(QRect(100, 260, 89, 25));
        pitchLabel = new QLabel(groupBox_4);
        pitchLabel->setObjectName(QStringLiteral("pitchLabel"));
        pitchLabel->setGeometry(QRect(190, 80, 67, 17));
        disableVirtualStickButton = new QPushButton(groupBox_4);
        disableVirtualStickButton->setObjectName(QStringLiteral("disableVirtualStickButton"));
        disableVirtualStickButton->setGeometry(QRect(170, 30, 131, 25));
        throttleSlider = new QSlider(groupBox_4);
        throttleSlider->setObjectName(QStringLiteral("throttleSlider"));
        throttleSlider->setGeometry(QRect(60, 130, 16, 121));
        throttleSlider->setOrientation(Qt::Vertical);
        throttleLabel = new QLabel(groupBox_4);
        throttleLabel->setObjectName(QStringLiteral("throttleLabel"));
        throttleLabel->setGeometry(QRect(80, 170, 67, 17));
        setRollButton = new QPushButton(groupBox_4);
        setRollButton->setObjectName(QStringLiteral("setRollButton"));
        setRollButton->setGeometry(QRect(230, 190, 61, 31));
        yawBiasLabel = new QLabel(groupBox_4);
        yawBiasLabel->setObjectName(QStringLiteral("yawBiasLabel"));
        yawBiasLabel->setGeometry(QRect(20, 60, 67, 17));
        pitchBiasLabel = new QLabel(groupBox_4);
        pitchBiasLabel->setObjectName(QStringLiteral("pitchBiasLabel"));
        pitchBiasLabel->setGeometry(QRect(190, 60, 67, 17));
        throttleBiasLabel = new QLabel(groupBox_4);
        throttleBiasLabel->setObjectName(QStringLiteral("throttleBiasLabel"));
        throttleBiasLabel->setGeometry(QRect(80, 150, 67, 17));
        rollBiasLabel = new QLabel(groupBox_4);
        rollBiasLabel->setObjectName(QStringLiteral("rollBiasLabel"));
        rollBiasLabel->setGeometry(QRect(230, 150, 67, 17));
        zoomSlider = new QSlider(groupBox_5);
        zoomSlider->setObjectName(QStringLiteral("zoomSlider"));
        zoomSlider->setGeometry(QRect(430, 40, 160, 16));
        zoomSlider->setOrientation(Qt::Horizontal);
        label_7 = new QLabel(groupBox_5);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(350, 40, 67, 17));
        goStraightButton = new QPushButton(groupBox_5);
        goStraightButton->setObjectName(QStringLiteral("goStraightButton"));
        goStraightButton->setGeometry(QRect(430, 240, 89, 21));
        turnLeftButton = new QPushButton(groupBox_5);
        turnLeftButton->setObjectName(QStringLiteral("turnLeftButton"));
        turnLeftButton->setGeometry(QRect(330, 240, 91, 21));
        turnRightButton = new QPushButton(groupBox_5);
        turnRightButton->setObjectName(QStringLiteral("turnRightButton"));
        turnRightButton->setGeometry(QRect(530, 240, 89, 21));
        turnLabel = new QLabel(groupBox_5);
        turnLabel->setObjectName(QStringLiteral("turnLabel"));
        turnLabel->setGeometry(QRect(420, 180, 111, 51));
        manulDirectCheckBox = new QCheckBox(groupBox_5);
        manulDirectCheckBox->setObjectName(QStringLiteral("manulDirectCheckBox"));
        manulDirectCheckBox->setGeometry(QRect(330, 270, 151, 23));
        navPointSlider = new QSlider(groupBox_5);
        navPointSlider->setObjectName(QStringLiteral("navPointSlider"));
        navPointSlider->setGeometry(QRect(430, 90, 160, 16));
        navPointSlider->setOrientation(Qt::Horizontal);
        label_9 = new QLabel(groupBox_5);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(350, 90, 67, 17));

        horizontalLayout_9->addWidget(groupBox_5);


        verticalLayout_2->addLayout(horizontalLayout_9);


        horizontalLayout_3->addLayout(verticalLayout_2);

        groupBox_3 = new QGroupBox(centralWidget);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setMinimumSize(QSize(450, 0));
        groupBox_3->setMaximumSize(QSize(200, 16777215));
        verticalLayout = new QVBoxLayout(groupBox_3);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        webView = new QWebEngineView(groupBox_3);
        webView->setObjectName(QStringLiteral("webView"));
        webView->setEnabled(true);
        webView->setMinimumSize(QSize(0, 300));
        webView->setMaximumSize(QSize(16777215, 16777215));

        verticalLayout->addWidget(webView);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        label_8 = new QLabel(groupBox_3);
        label_8->setObjectName(QStringLiteral("label_8"));

        horizontalLayout_8->addWidget(label_8);

        VelV = new QLabel(groupBox_3);
        VelV->setObjectName(QStringLiteral("VelV"));

        horizontalLayout_8->addWidget(VelV);

        label_12 = new QLabel(groupBox_3);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setMinimumSize(QSize(0, 0));

        horizontalLayout_8->addWidget(label_12);


        horizontalLayout_5->addLayout(horizontalLayout_8);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_6 = new QLabel(groupBox_3);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout_6->addWidget(label_6);

        VelH = new QLabel(groupBox_3);
        VelH->setObjectName(QStringLiteral("VelH"));
        VelH->setMinimumSize(QSize(0, 30));

        horizontalLayout_6->addWidget(VelH);

        label_14 = new QLabel(groupBox_3);
        label_14->setObjectName(QStringLiteral("label_14"));

        horizontalLayout_6->addWidget(label_14);


        horizontalLayout_5->addLayout(horizontalLayout_6);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_10 = new QLabel(groupBox_3);
        label_10->setObjectName(QStringLiteral("label_10"));

        horizontalLayout_2->addWidget(label_10);

        Bat = new QLabel(groupBox_3);
        Bat->setObjectName(QStringLiteral("Bat"));

        horizontalLayout_2->addWidget(Bat);

        label_13 = new QLabel(groupBox_3);
        label_13->setObjectName(QStringLiteral("label_13"));

        horizontalLayout_2->addWidget(label_13);


        horizontalLayout_5->addLayout(horizontalLayout_2);


        verticalLayout->addLayout(horizontalLayout_5);

        groupBox = new QGroupBox(groupBox_3);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        horizontalLayout = new QHBoxLayout(groupBox);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout->addWidget(pushButton);

        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        lineEditLat = new QLineEdit(groupBox);
        lineEditLat->setObjectName(QStringLiteral("lineEditLat"));
        lineEditLat->setMinimumSize(QSize(60, 0));

        horizontalLayout->addWidget(lineEditLat);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout->addWidget(label_2);

        lineEditLng = new QLineEdit(groupBox);
        lineEditLng->setObjectName(QStringLiteral("lineEditLng"));
        lineEditLng->setMinimumSize(QSize(60, 0));
        lineEditLng->setCursorPosition(8);

        horizontalLayout->addWidget(lineEditLng);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout->addWidget(label_4);

        Alt = new QLabel(groupBox);
        Alt->setObjectName(QStringLiteral("Alt"));

        horizontalLayout->addWidget(Alt);


        verticalLayout->addWidget(groupBox);

        groupBox1 = new QGroupBox(groupBox_3);
        groupBox1->setObjectName(QStringLiteral("groupBox1"));
        horizontalLayout_7 = new QHBoxLayout(groupBox1);
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        cbLight = new QComboBox(groupBox1);
        cbLight->setObjectName(QStringLiteral("cbLight"));

        horizontalLayout_7->addWidget(cbLight);

        btnAdd = new QPushButton(groupBox1);
        btnAdd->setObjectName(QStringLiteral("btnAdd"));

        horizontalLayout_7->addWidget(btnAdd);

        clearAllPointButton = new QPushButton(groupBox1);
        clearAllPointButton->setObjectName(QStringLiteral("clearAllPointButton"));

        horizontalLayout_7->addWidget(clearAllPointButton);

        takeoffButton = new QPushButton(groupBox1);
        takeoffButton->setObjectName(QStringLiteral("takeoffButton"));

        horizontalLayout_7->addWidget(takeoffButton);

        waypointAlt = new QLineEdit(groupBox1);
        waypointAlt->setObjectName(QStringLiteral("waypointAlt"));

        horizontalLayout_7->addWidget(waypointAlt);

        goButton = new QPushButton(groupBox1);
        goButton->setObjectName(QStringLiteral("goButton"));

        horizontalLayout_7->addWidget(goButton);


        verticalLayout->addWidget(groupBox1);

        groupBox_2 = new QGroupBox(groupBox_3);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        horizontalLayout_4 = new QHBoxLayout(groupBox_2);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        detect_carButton = new QPushButton(groupBox_2);
        detect_carButton->setObjectName(QStringLiteral("detect_carButton"));

        horizontalLayout_4->addWidget(detect_carButton);

        track_carButton = new QPushButton(groupBox_2);
        track_carButton->setObjectName(QStringLiteral("track_carButton"));

        horizontalLayout_4->addWidget(track_carButton);

        do_nothing = new QPushButton(groupBox_2);
        do_nothing->setObjectName(QStringLiteral("do_nothing"));

        horizontalLayout_4->addWidget(do_nothing);

        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_4->addWidget(label_5);

        lineEditnumber = new QLineEdit(groupBox_2);
        lineEditnumber->setObjectName(QStringLiteral("lineEditnumber"));

        horizontalLayout_4->addWidget(lineEditnumber);


        verticalLayout->addWidget(groupBox_2);


        horizontalLayout_3->addWidget(groupBox_3);

        MainWindow->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        label_3->setText(QString());
        groupBox_5->setTitle(QApplication::translate("MainWindow", "                                                                                             Add navigation point", nullptr));
        groupBox_4->setTitle(QApplication::translate("MainWindow", "Virtual stick", nullptr));
        enableVirtualStickButton->setText(QApplication::translate("MainWindow", "Enable virtual Stick", nullptr));
        yawLabel->setText(QApplication::translate("MainWindow", "Yaw", nullptr));
        rollLabel->setText(QApplication::translate("MainWindow", "Roll", nullptr));
        onRestStickValueButton->setText(QApplication::translate("MainWindow", "reset", nullptr));
        pitchLabel->setText(QApplication::translate("MainWindow", "Pitch", nullptr));
        disableVirtualStickButton->setText(QApplication::translate("MainWindow", "Disable virtual S", nullptr));
        throttleLabel->setText(QApplication::translate("MainWindow", "Throttle", nullptr));
        setRollButton->setText(QApplication::translate("MainWindow", "Set", nullptr));
        yawBiasLabel->setText(QString());
        pitchBiasLabel->setText(QString());
        throttleBiasLabel->setText(QString());
        rollBiasLabel->setText(QString());
        label_7->setText(QApplication::translate("MainWindow", "Zoom", nullptr));
        goStraightButton->setText(QApplication::translate("MainWindow", "Go straight", nullptr));
        turnLeftButton->setText(QApplication::translate("MainWindow", "Turn left", nullptr));
        turnRightButton->setText(QApplication::translate("MainWindow", "Turn right", nullptr));
        turnLabel->setText(QString());
        manulDirectCheckBox->setText(QApplication::translate("MainWindow", "Manul direct", nullptr));
        label_9->setText(QApplication::translate("MainWindow", "Nav point", nullptr));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "Map", nullptr));
        label_8->setText(QApplication::translate("MainWindow", "Velocity_V:", nullptr));
        VelV->setText(QApplication::translate("MainWindow", "3.3", nullptr));
        label_12->setText(QApplication::translate("MainWindow", "m/s", nullptr));
        label_6->setText(QApplication::translate("MainWindow", "Velocity_H:", nullptr));
        VelH->setText(QApplication::translate("MainWindow", "3.3", nullptr));
        label_14->setText(QApplication::translate("MainWindow", "m/s", nullptr));
        label_10->setText(QApplication::translate("MainWindow", "Battery:", nullptr));
        Bat->setText(QApplication::translate("MainWindow", "99", nullptr));
        label_13->setText(QApplication::translate("MainWindow", "%", nullptr));
        groupBox->setTitle(QApplication::translate("MainWindow", "GPS Data", nullptr));
        pushButton->setText(QApplication::translate("MainWindow", "Map_Refresh", nullptr));
        label->setText(QApplication::translate("MainWindow", "Lat", nullptr));
        lineEditLat->setText(QApplication::translate("MainWindow", "29.6169", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "Lng", nullptr));
        lineEditLng->setText(QApplication::translate("MainWindow", "106.4988", nullptr));
        label_4->setText(QApplication::translate("MainWindow", " Alt ", nullptr));
        Alt->setText(QApplication::translate("MainWindow", "000.0", nullptr));
        groupBox1->setTitle(QApplication::translate("MainWindow", "WayPoints", nullptr));
        btnAdd->setText(QApplication::translate("MainWindow", "Add", nullptr));
        clearAllPointButton->setText(QApplication::translate("MainWindow", "Clear", nullptr));
        takeoffButton->setText(QApplication::translate("MainWindow", "TakeOff", nullptr));
        goButton->setText(QApplication::translate("MainWindow", "Go", nullptr));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "Car detection", nullptr));
        detect_carButton->setText(QApplication::translate("MainWindow", "detect_car", nullptr));
        track_carButton->setText(QApplication::translate("MainWindow", "track_car", nullptr));
        do_nothing->setText(QApplication::translate("MainWindow", "wait", nullptr));
        label_5->setText(QApplication::translate("MainWindow", "     number:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
