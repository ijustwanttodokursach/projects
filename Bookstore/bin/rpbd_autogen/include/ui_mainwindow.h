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
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTabWidget *tabWidget;
    QWidget *tab;
    QWidget *widget;
    QPushButton *pushButton_4;
    QPushButton *pushButton_6;
    QWidget *tab_2;
    QListWidget *listP;
    QLabel *label;
    QLabel *label_2;
    QListWidget *listB;
    QPushButton *pushButton;
    QLabel *label_3;
    QListWidget *listI;
    QPushButton *pushButton_2;
    QPushButton *pushButton_5;
    QGroupBox *groupBox;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QPushButton *pushButton_3;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(982, 612);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setGeometry(QRect(0, 10, 971, 561));
        tab = new QWidget();
        tab->setObjectName("tab");
        widget = new QWidget(tab);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(0, 0, 961, 481));
        pushButton_4 = new QPushButton(tab);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(280, 490, 121, 31));
        QFont font;
        font.setPointSize(16);
        font.setBold(true);
        pushButton_4->setFont(font);
        pushButton_6 = new QPushButton(tab);
        pushButton_6->setObjectName("pushButton_6");
        pushButton_6->setGeometry(QRect(470, 490, 121, 31));
        pushButton_6->setFont(font);
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        listP = new QListWidget(tab_2);
        listP->setObjectName("listP");
        listP->setGeometry(QRect(10, 30, 171, 321));
        label = new QLabel(tab_2);
        label->setObjectName("label");
        label->setGeometry(QRect(50, 0, 91, 31));
        label->setFont(font);
        label_2 = new QLabel(tab_2);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(280, 0, 131, 31));
        label_2->setFont(font);
        listB = new QListWidget(tab_2);
        listB->setObjectName("listB");
        listB->setGeometry(QRect(200, 30, 281, 321));
        pushButton = new QPushButton(tab_2);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(50, 360, 80, 24));
        pushButton->setFont(font);
        label_3 = new QLabel(tab_2);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(700, 0, 61, 31));
        label_3->setFont(font);
        listI = new QListWidget(tab_2);
        listI->setObjectName("listI");
        listI->setGeometry(QRect(490, 30, 471, 321));
        pushButton_2 = new QPushButton(tab_2);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(490, 360, 80, 24));
        pushButton_2->setFont(font);
        pushButton_5 = new QPushButton(tab_2);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setGeometry(QRect(880, 360, 80, 24));
        pushButton_5->setFont(font);
        groupBox = new QGroupBox(tab_2);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(0, 390, 251, 131));
        QFont font1;
        font1.setPointSize(12);
        font1.setBold(true);
        groupBox->setFont(font1);
        lineEdit = new QLineEdit(groupBox);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(0, 30, 241, 24));
        lineEdit_2 = new QLineEdit(groupBox);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setGeometry(QRect(0, 60, 241, 24));
        lineEdit_3 = new QLineEdit(groupBox);
        lineEdit_3->setObjectName("lineEdit_3");
        lineEdit_3->setGeometry(QRect(0, 90, 241, 24));
        label_4 = new QLabel(tab_2);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(260, 420, 71, 16));
        QFont font2;
        font2.setPointSize(14);
        font2.setBold(true);
        label_4->setFont(font2);
        label_5 = new QLabel(tab_2);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(260, 450, 81, 16));
        label_5->setFont(font2);
        label_6 = new QLabel(tab_2);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(260, 480, 81, 16));
        label_6->setFont(font2);
        pushButton_3 = new QPushButton(tab_2);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(370, 420, 80, 91));
        pushButton_3->setFont(font);
        tabWidget->addTab(tab_2, QString());
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 982, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Library Database", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "Bar chart", nullptr));
        pushButton_6->setText(QCoreApplication::translate("MainWindow", "Pie chart", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("MainWindow", "Tab 1", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Patrons", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Book Copies", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Debt", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Issues", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "Add", nullptr));
        pushButton_5->setText(QCoreApplication::translate("MainWindow", "Delete", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "User Add", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Phone", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Surname", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Adress", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "Insert", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("MainWindow", "Tab 2", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
