/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include <qcustomplot.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLabel *label;
    QLineEdit *outTn;
    QLabel *label_2;
    QLineEdit *outTd;
    QLabel *label_3;
    QSlider *inV0;
    QSlider *inK;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QSlider *inM;
    QSlider *inU0;
    QSlider *inZ;
    QLineEdit *outUmax;
    QCustomPlot *responsePlot;
    QLineEdit *outZ_3;
    QLineEdit *outZ;
    QLineEdit *outK;
    QLineEdit *outM;
    QLineEdit *outU0;
    QLineEdit *outV0;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(683, 560);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(400, 10, 20, 21));
        outTn = new QLineEdit(centralWidget);
        outTn->setObjectName(QStringLiteral("outTn"));
        outTn->setGeometry(QRect(430, 10, 51, 21));
        outTn->setReadOnly(true);
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(490, 10, 20, 21));
        outTd = new QLineEdit(centralWidget);
        outTd->setObjectName(QStringLiteral("outTd"));
        outTd->setGeometry(QRect(510, 10, 51, 21));
        outTd->setReadOnly(true);
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(570, 10, 20, 21));
        inV0 = new QSlider(centralWidget);
        inV0->setObjectName(QStringLiteral("inV0"));
        inV0->setGeometry(QRect(30, 10, 22, 171));
        inV0->setMaximum(200);
        inV0->setOrientation(Qt::Vertical);
        inV0->setTickPosition(QSlider::TicksBothSides);
        inK = new QSlider(centralWidget);
        inK->setObjectName(QStringLiteral("inK"));
        inK->setGeometry(QRect(280, 480, 171, 22));
        inK->setMinimum(0);
        inK->setMaximum(200);
        inK->setOrientation(Qt::Horizontal);
        inK->setTickPosition(QSlider::TicksBothSides);
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(40, 480, 21, 16));
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(260, 480, 21, 16));
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(480, 480, 16, 16));
        QFont font;
        font.setFamily(QStringLiteral("Symbol"));
        label_6->setFont(font);
        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(30, 420, 31, 20));
        label_8 = new QLabel(centralWidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(30, 180, 31, 20));
        inM = new QSlider(centralWidget);
        inM->setObjectName(QStringLiteral("inM"));
        inM->setGeometry(QRect(60, 480, 181, 22));
        inM->setMinimum(0);
        inM->setMaximum(200);
        inM->setOrientation(Qt::Horizontal);
        inM->setTickPosition(QSlider::TicksBothSides);
        inU0 = new QSlider(centralWidget);
        inU0->setObjectName(QStringLiteral("inU0"));
        inU0->setGeometry(QRect(30, 250, 22, 171));
        inU0->setMaximum(200);
        inU0->setOrientation(Qt::Vertical);
        inU0->setTickPosition(QSlider::TicksBothSides);
        inZ = new QSlider(centralWidget);
        inZ->setObjectName(QStringLiteral("inZ"));
        inZ->setGeometry(QRect(500, 480, 161, 22));
        inZ->setMinimum(0);
        inZ->setMaximum(100);
        inZ->setOrientation(Qt::Horizontal);
        inZ->setTickPosition(QSlider::TicksBothSides);
        inZ->setTickInterval(20);
        outUmax = new QLineEdit(centralWidget);
        outUmax->setObjectName(QStringLiteral("outUmax"));
        outUmax->setGeometry(QRect(600, 10, 51, 21));
        outUmax->setReadOnly(true);
        responsePlot = new QCustomPlot(centralWidget);
        responsePlot->setObjectName(QStringLiteral("responsePlot"));
        responsePlot->setGeometry(QRect(60, 40, 591, 421));
        outZ_3 = new QLineEdit(responsePlot);
        outZ_3->setObjectName(QStringLiteral("outZ_3"));
        outZ_3->setGeometry(QRect(70, 420, 61, 21));
        outZ = new QLineEdit(centralWidget);
        outZ->setObjectName(QStringLiteral("outZ"));
        outZ->setGeometry(QRect(560, 460, 61, 21));
        outK = new QLineEdit(centralWidget);
        outK->setObjectName(QStringLiteral("outK"));
        outK->setGeometry(QRect(340, 460, 61, 21));
        outM = new QLineEdit(centralWidget);
        outM->setObjectName(QStringLiteral("outM"));
        outM->setGeometry(QRect(130, 460, 61, 21));
        outU0 = new QLineEdit(centralWidget);
        outU0->setObjectName(QStringLiteral("outU0"));
        outU0->setGeometry(QRect(10, 440, 61, 21));
        outV0 = new QLineEdit(centralWidget);
        outV0->setObjectName(QStringLiteral("outV0"));
        outV0->setGeometry(QRect(10, 200, 61, 21));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 683, 22));
        MainWindow->setMenuBar(menuBar);
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
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        label->setText(QApplication::translate("MainWindow", "Tn:", 0));
        label_2->setText(QApplication::translate("MainWindow", "Td:", 0));
        label_3->setText(QApplication::translate("MainWindow", "U0:", 0));
        label_4->setText(QApplication::translate("MainWindow", "M", 0));
        label_5->setText(QApplication::translate("MainWindow", "K", 0));
        label_6->setText(QApplication::translate("MainWindow", "z", 0));
        label_7->setText(QApplication::translate("MainWindow", "U(0)", 0));
        label_8->setText(QApplication::translate("MainWindow", "V(0)", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
