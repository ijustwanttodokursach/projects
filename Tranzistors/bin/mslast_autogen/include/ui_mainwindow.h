/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *widget;
    QPushButton *pushButton;
    QLineEdit *lineEdit;
    QLabel *label;
    QLineEdit *lineEdit_2;
    QLabel *label_2;
    QGroupBox *groupBox;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QLabel *label_3;
    QLineEdit *lineEdit_3;
    QWidget *widget_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1320, 625);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        widget = new QWidget(centralwidget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(40, 50, 661, 521));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(740, 90, 161, 91));
        QFont font;
        font.setPointSize(36);
        font.setBold(true);
        pushButton->setFont(font);
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(760, 50, 113, 24));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(710, 10, 221, 31));
        QFont font1;
        font1.setPointSize(18);
        label->setFont(font1);
        lineEdit_2 = new QLineEdit(centralwidget);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setGeometry(QRect(760, 290, 113, 24));
        lineEdit_2->setReadOnly(false);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(730, 250, 171, 31));
        label_2->setFont(font1);
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(750, 450, 161, 91));
        QFont font2;
        font2.setPointSize(12);
        font2.setBold(true);
        font2.setItalic(true);
        groupBox->setFont(font2);
        radioButton = new QRadioButton(groupBox);
        radioButton->setObjectName("radioButton");
        radioButton->setGeometry(QRect(20, 30, 121, 22));
        radioButton->setChecked(true);
        radioButton_2 = new QRadioButton(groupBox);
        radioButton_2->setObjectName("radioButton_2");
        radioButton_2->setGeometry(QRect(20, 60, 121, 22));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(720, 330, 181, 31));
        label_3->setFont(font1);
        lineEdit_3 = new QLineEdit(centralwidget);
        lineEdit_3->setObjectName("lineEdit_3");
        lineEdit_3->setGeometry(QRect(760, 370, 113, 24));
        widget_2 = new QWidget(centralwidget);
        widget_2->setObjectName("widget_2");
        widget_2->setGeometry(QRect(940, 10, 371, 321));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1320, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Tranzistors", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Run!", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "SET DURATION HERE", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "DAMAGE DONE", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "Select units to change", nullptr));
        radioButton->setText(QCoreApplication::translate("MainWindow", "Change ALL", nullptr));
        radioButton_2->setText(QCoreApplication::translate("MainWindow", "Change ONE", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "UNITS CHANGED", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
