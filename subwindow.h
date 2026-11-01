/********************************************************************************
** Form generated from reading UI file 'subwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef SUBWINDOW_H
#define SUBWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TreasureHunt_SubWindow
{
public:
    QSpinBox *spinbox;
    QPushButton *GO;
    QGroupBox *groupBox;
    QLCDNumber *count;
    QLabel *label;
    QLCDNumber *difficulty;
    QLabel *label_2;
    QLabel *label_clear;
    QPushButton *giveup;

    void setupUi(QWidget *TreasureHunt_SubWindow)
    {
        if (TreasureHunt_SubWindow->objectName().isEmpty())
            TreasureHunt_SubWindow->setObjectName("TreasureHunt_SubWindow");
        TreasureHunt_SubWindow->resize(261, 100);
        spinbox = new QSpinBox(TreasureHunt_SubWindow);
        spinbox->setObjectName("spinbox");
        spinbox->setGeometry(QRect(0, 0, 81, 25));
        spinbox->setMaximum(999999999);
        spinbox->setSingleStep(0);
        spinbox->setValue(20);
        GO = new QPushButton(TreasureHunt_SubWindow);
        GO->setObjectName("GO");
        GO->setGeometry(QRect(80, 0, 181, 25));
        GO->setStyleSheet(QString::fromUtf8("background-color: #1E88E6"));
        groupBox = new QGroupBox(TreasureHunt_SubWindow);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(0, 30, 261, 71));
        count = new QLCDNumber(groupBox);
        count->setObjectName("count");
        count->setGeometry(QRect(50, 45, 211, 23));
        count->setStyleSheet(QString::fromUtf8("background-color: green"));
        count->setDigitCount(20);
        label = new QLabel(groupBox);
        label->setObjectName("label");
        label->setGeometry(QRect(0, 45, 51, 23));
        difficulty = new QLCDNumber(groupBox);
        difficulty->setObjectName("difficulty");
        difficulty->setGeometry(QRect(50, 20, 211, 23));
        difficulty->setStyleSheet(QString::fromUtf8("background-color: green"));
        difficulty->setDigitCount(20);
        label_2 = new QLabel(groupBox);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(0, 20, 51, 23));
        label_clear = new QLabel(TreasureHunt_SubWindow);
        label_clear->setObjectName("label_clear");
        label_clear->setGeometry(QRect(80, 25, 181, 20));
        label_clear->setStyleSheet(QString::fromUtf8("background-color: black;color: white;"));
        giveup = new QPushButton(TreasureHunt_SubWindow);
        giveup->setObjectName("giveup");
        giveup->setGeometry(QRect(34, 25, 46, 20));
        giveup->setStyleSheet(QString::fromUtf8("background-color: red;color: white"));

        retranslateUi(TreasureHunt_SubWindow);

        QMetaObject::connectSlotsByName(TreasureHunt_SubWindow);
    } // setupUi

    void retranslateUi(QWidget *TreasureHunt_SubWindow)
    {
        TreasureHunt_SubWindow->setWindowTitle(QCoreApplication::translate("TreasureHunt_SubWindow", "GameControlWindow", nullptr));
        GO->setText(QCoreApplication::translate("TreasureHunt_SubWindow", "GO", nullptr));
        groupBox->setTitle(QCoreApplication::translate("TreasureHunt_SubWindow", "Data", nullptr));
        label->setText(QCoreApplication::translate("TreasureHunt_SubWindow", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:700;\">\343\202\253\343\202\246\343\203\263\343\203\210</span></p></body></html>", nullptr));
        label_2->setText(QCoreApplication::translate("TreasureHunt_SubWindow", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:700;\">\351\233\243\346\230\223\345\272\246</span></p></body></html>", nullptr));
        label_clear->setText(QString());
        giveup->setText(QCoreApplication::translate("TreasureHunt_SubWindow", "give up", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TreasureHunt_SubWindow: public Ui_TreasureHunt_SubWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // SUBWINDOW_H
