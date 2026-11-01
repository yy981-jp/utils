/********************************************************************************
** Form generated from reading UI file 'lock.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef LOCK_H
#define LOCK_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_lock
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QGroupBox *MENU;
    QGridLayout *gridLayout_5;
    QGroupBox *screensaver_box;
    QGridLayout *gridLayout_3;
    QSlider *screensaver_darkness;
    QComboBox *screensaver_type;
    QLabel *screensaver_darkness_label;
    QPushButton *screensaver_start;
    QLabel *screensaver_type_label;
    QGroupBox *shortcut1_box;
    QHBoxLayout *horizontalLayout;
    QCheckBox *shortcut_enable_1;
    QFrame *line1_2;
    QCheckBox *shortcut_black_1;
    QFrame *line1_1;
    QComboBox *shortcut_modifier_1;
    QComboBox *shortcut_key_1;
    QGroupBox *schedule_box;
    QGridLayout *gridLayout_4;
    QTimeEdit *schedule_time_4;
    QCheckBox *schedule_check_2;
    QCheckBox *schedule_check_3;
    QTimeEdit *schedule_time_5;
    QCheckBox *schedule_check_6;
    QCheckBox *schedule_check_4;
    QTimeEdit *schedule_time_2;
    QTimeEdit *schedule_time_1;
    QTimeEdit *schedule_time_6;
    QTimeEdit *schedule_time_3;
    QCheckBox *schedule_check_1;
    QCheckBox *schedule_check_5;
    QGroupBox *shortcut2_box;
    QHBoxLayout *horizontalLayout_2;
    QCheckBox *shortcut_enable_2;
    QFrame *line2_2;
    QCheckBox *shortcut_black_2;
    QFrame *line2_1;
    QComboBox *shortcut_modifier_2;
    QComboBox *shortcut_key_2;
    QGroupBox *other_box;
    QVBoxLayout *verticalLayout;
    QCheckBox *other_1;
    QCheckBox *other_2;
    QPushButton *pushButton2;
    QPushButton *pushButton;
    QLineEdit *lineEdit1;
    QLineEdit *lineEdit2;

    void setupUi(QMainWindow *lock)
    {
        if (lock->objectName().isEmpty())
            lock->setObjectName("lock");
        lock->resize(1000, 600);
        centralwidget = new QWidget(lock);
        centralwidget->setObjectName("centralwidget");
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName("gridLayout");
        MENU = new QGroupBox(centralwidget);
        MENU->setObjectName("MENU");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MENU->sizePolicy().hasHeightForWidth());
        MENU->setSizePolicy(sizePolicy);
        MENU->setFlat(false);
        MENU->setCheckable(false);
        MENU->setChecked(false);
        gridLayout_5 = new QGridLayout(MENU);
        gridLayout_5->setObjectName("gridLayout_5");
        screensaver_box = new QGroupBox(MENU);
        screensaver_box->setObjectName("screensaver_box");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(screensaver_box->sizePolicy().hasHeightForWidth());
        screensaver_box->setSizePolicy(sizePolicy1);
        gridLayout_3 = new QGridLayout(screensaver_box);
        gridLayout_3->setObjectName("gridLayout_3");
        screensaver_darkness = new QSlider(screensaver_box);
        screensaver_darkness->setObjectName("screensaver_darkness");
        screensaver_darkness->setMinimum(1);
        screensaver_darkness->setMaximum(100);
        screensaver_darkness->setOrientation(Qt::Orientation::Horizontal);

        gridLayout_3->addWidget(screensaver_darkness, 0, 1, 1, 1);

        screensaver_type = new QComboBox(screensaver_box);
        screensaver_type->addItem(QString());
        screensaver_type->addItem(QString());
        screensaver_type->setObjectName("screensaver_type");

        gridLayout_3->addWidget(screensaver_type, 1, 1, 1, 1);

        screensaver_darkness_label = new QLabel(screensaver_box);
        screensaver_darkness_label->setObjectName("screensaver_darkness_label");

        gridLayout_3->addWidget(screensaver_darkness_label, 0, 0, 1, 1);

        screensaver_start = new QPushButton(screensaver_box);
        screensaver_start->setObjectName("screensaver_start");
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(screensaver_start->sizePolicy().hasHeightForWidth());
        screensaver_start->setSizePolicy(sizePolicy2);

        gridLayout_3->addWidget(screensaver_start, 2, 0, 1, 2);

        screensaver_type_label = new QLabel(screensaver_box);
        screensaver_type_label->setObjectName("screensaver_type_label");

        gridLayout_3->addWidget(screensaver_type_label, 1, 0, 1, 1);


        gridLayout_5->addWidget(screensaver_box, 1, 4, 2, 1);

        shortcut1_box = new QGroupBox(MENU);
        shortcut1_box->setObjectName("shortcut1_box");
        horizontalLayout = new QHBoxLayout(shortcut1_box);
        horizontalLayout->setObjectName("horizontalLayout");
        shortcut_enable_1 = new QCheckBox(shortcut1_box);
        shortcut_enable_1->setObjectName("shortcut_enable_1");

        horizontalLayout->addWidget(shortcut_enable_1);

        line1_2 = new QFrame(shortcut1_box);
        line1_2->setObjectName("line1_2");
        line1_2->setFrameShadow(QFrame::Shadow::Plain);
        line1_2->setLineWidth(10);
        line1_2->setFrameShape(QFrame::Shape::VLine);

        horizontalLayout->addWidget(line1_2);

        shortcut_black_1 = new QCheckBox(shortcut1_box);
        shortcut_black_1->setObjectName("shortcut_black_1");

        horizontalLayout->addWidget(shortcut_black_1);

        line1_1 = new QFrame(shortcut1_box);
        line1_1->setObjectName("line1_1");
        line1_1->setFrameShape(QFrame::Shape::VLine);
        line1_1->setFrameShadow(QFrame::Shadow::Sunken);

        horizontalLayout->addWidget(line1_1);

        shortcut_modifier_1 = new QComboBox(shortcut1_box);
        shortcut_modifier_1->addItem(QString());
        shortcut_modifier_1->addItem(QString());
        shortcut_modifier_1->addItem(QString());
        shortcut_modifier_1->addItem(QString());
        shortcut_modifier_1->addItem(QString());
        shortcut_modifier_1->addItem(QString());
        shortcut_modifier_1->addItem(QString());
        shortcut_modifier_1->addItem(QString());
        shortcut_modifier_1->addItem(QString());
        shortcut_modifier_1->addItem(QString());
        shortcut_modifier_1->addItem(QString());
        shortcut_modifier_1->addItem(QString());
        shortcut_modifier_1->addItem(QString());
        shortcut_modifier_1->addItem(QString());
        shortcut_modifier_1->addItem(QString());
        shortcut_modifier_1->addItem(QString());
        shortcut_modifier_1->setObjectName("shortcut_modifier_1");

        horizontalLayout->addWidget(shortcut_modifier_1);

        shortcut_key_1 = new QComboBox(shortcut1_box);
        shortcut_key_1->addItem(QString());
        shortcut_key_1->addItem(QString());
        shortcut_key_1->addItem(QString());
        shortcut_key_1->addItem(QString());
        shortcut_key_1->addItem(QString());
        shortcut_key_1->addItem(QString());
        shortcut_key_1->addItem(QString());
        shortcut_key_1->addItem(QString());
        shortcut_key_1->addItem(QString());
        shortcut_key_1->addItem(QString());
        shortcut_key_1->addItem(QString());
        shortcut_key_1->addItem(QString());
        shortcut_key_1->addItem(QString());
        shortcut_key_1->addItem(QString());
        shortcut_key_1->addItem(QString());
        shortcut_key_1->addItem(QString());
        shortcut_key_1->addItem(QString());
        shortcut_key_1->addItem(QString());
        shortcut_key_1->addItem(QString());
        shortcut_key_1->addItem(QString());
        shortcut_key_1->addItem(QString());
        shortcut_key_1->addItem(QString());
        shortcut_key_1->addItem(QString());
        shortcut_key_1->addItem(QString());
        shortcut_key_1->addItem(QString());
        shortcut_key_1->addItem(QString());
        shortcut_key_1->addItem(QString());
        shortcut_key_1->setObjectName("shortcut_key_1");

        horizontalLayout->addWidget(shortcut_key_1);


        gridLayout_5->addWidget(shortcut1_box, 1, 1, 1, 2);

        schedule_box = new QGroupBox(MENU);
        schedule_box->setObjectName("schedule_box");
        gridLayout_4 = new QGridLayout(schedule_box);
        gridLayout_4->setObjectName("gridLayout_4");
        schedule_time_4 = new QTimeEdit(schedule_box);
        schedule_time_4->setObjectName("schedule_time_4");

        gridLayout_4->addWidget(schedule_time_4, 1, 3, 1, 1);

        schedule_check_2 = new QCheckBox(schedule_box);
        schedule_check_2->setObjectName("schedule_check_2");
        schedule_check_2->setTristate(true);

        gridLayout_4->addWidget(schedule_check_2, 2, 0, 1, 1);

        schedule_check_3 = new QCheckBox(schedule_box);
        schedule_check_3->setObjectName("schedule_check_3");
        schedule_check_3->setTristate(true);

        gridLayout_4->addWidget(schedule_check_3, 5, 0, 1, 1);

        schedule_time_5 = new QTimeEdit(schedule_box);
        schedule_time_5->setObjectName("schedule_time_5");

        gridLayout_4->addWidget(schedule_time_5, 2, 3, 1, 1);

        schedule_check_6 = new QCheckBox(schedule_box);
        schedule_check_6->setObjectName("schedule_check_6");
        schedule_check_6->setTristate(true);

        gridLayout_4->addWidget(schedule_check_6, 5, 2, 1, 1);

        schedule_check_4 = new QCheckBox(schedule_box);
        schedule_check_4->setObjectName("schedule_check_4");
        schedule_check_4->setTristate(true);

        gridLayout_4->addWidget(schedule_check_4, 1, 2, 1, 1);

        schedule_time_2 = new QTimeEdit(schedule_box);
        schedule_time_2->setObjectName("schedule_time_2");

        gridLayout_4->addWidget(schedule_time_2, 2, 1, 1, 1);

        schedule_time_1 = new QTimeEdit(schedule_box);
        schedule_time_1->setObjectName("schedule_time_1");
        schedule_time_1->setWrapping(false);
        schedule_time_1->setButtonSymbols(QAbstractSpinBox::ButtonSymbols::UpDownArrows);

        gridLayout_4->addWidget(schedule_time_1, 1, 1, 1, 1);

        schedule_time_6 = new QTimeEdit(schedule_box);
        schedule_time_6->setObjectName("schedule_time_6");

        gridLayout_4->addWidget(schedule_time_6, 5, 3, 1, 1);

        schedule_time_3 = new QTimeEdit(schedule_box);
        schedule_time_3->setObjectName("schedule_time_3");

        gridLayout_4->addWidget(schedule_time_3, 5, 1, 1, 1);

        schedule_check_1 = new QCheckBox(schedule_box);
        schedule_check_1->setObjectName("schedule_check_1");
        schedule_check_1->setTristate(true);

        gridLayout_4->addWidget(schedule_check_1, 1, 0, 1, 1);

        schedule_check_5 = new QCheckBox(schedule_box);
        schedule_check_5->setObjectName("schedule_check_5");
        schedule_check_5->setTristate(true);

        gridLayout_4->addWidget(schedule_check_5, 2, 2, 1, 1);


        gridLayout_5->addWidget(schedule_box, 1, 0, 2, 1);

        shortcut2_box = new QGroupBox(MENU);
        shortcut2_box->setObjectName("shortcut2_box");
        horizontalLayout_2 = new QHBoxLayout(shortcut2_box);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        shortcut_enable_2 = new QCheckBox(shortcut2_box);
        shortcut_enable_2->setObjectName("shortcut_enable_2");

        horizontalLayout_2->addWidget(shortcut_enable_2);

        line2_2 = new QFrame(shortcut2_box);
        line2_2->setObjectName("line2_2");
        line2_2->setFrameShadow(QFrame::Shadow::Plain);
        line2_2->setLineWidth(10);
        line2_2->setFrameShape(QFrame::Shape::VLine);

        horizontalLayout_2->addWidget(line2_2);

        shortcut_black_2 = new QCheckBox(shortcut2_box);
        shortcut_black_2->setObjectName("shortcut_black_2");

        horizontalLayout_2->addWidget(shortcut_black_2);

        line2_1 = new QFrame(shortcut2_box);
        line2_1->setObjectName("line2_1");
        line2_1->setFrameShape(QFrame::Shape::VLine);
        line2_1->setFrameShadow(QFrame::Shadow::Sunken);

        horizontalLayout_2->addWidget(line2_1);

        shortcut_modifier_2 = new QComboBox(shortcut2_box);
        shortcut_modifier_2->addItem(QString());
        shortcut_modifier_2->addItem(QString());
        shortcut_modifier_2->addItem(QString());
        shortcut_modifier_2->addItem(QString());
        shortcut_modifier_2->addItem(QString());
        shortcut_modifier_2->addItem(QString());
        shortcut_modifier_2->addItem(QString());
        shortcut_modifier_2->addItem(QString());
        shortcut_modifier_2->addItem(QString());
        shortcut_modifier_2->addItem(QString());
        shortcut_modifier_2->addItem(QString());
        shortcut_modifier_2->addItem(QString());
        shortcut_modifier_2->addItem(QString());
        shortcut_modifier_2->addItem(QString());
        shortcut_modifier_2->addItem(QString());
        shortcut_modifier_2->addItem(QString());
        shortcut_modifier_2->setObjectName("shortcut_modifier_2");

        horizontalLayout_2->addWidget(shortcut_modifier_2);

        shortcut_key_2 = new QComboBox(shortcut2_box);
        shortcut_key_2->addItem(QString());
        shortcut_key_2->addItem(QString());
        shortcut_key_2->addItem(QString());
        shortcut_key_2->addItem(QString());
        shortcut_key_2->addItem(QString());
        shortcut_key_2->addItem(QString());
        shortcut_key_2->addItem(QString());
        shortcut_key_2->addItem(QString());
        shortcut_key_2->addItem(QString());
        shortcut_key_2->addItem(QString());
        shortcut_key_2->addItem(QString());
        shortcut_key_2->addItem(QString());
        shortcut_key_2->addItem(QString());
        shortcut_key_2->addItem(QString());
        shortcut_key_2->addItem(QString());
        shortcut_key_2->addItem(QString());
        shortcut_key_2->addItem(QString());
        shortcut_key_2->addItem(QString());
        shortcut_key_2->addItem(QString());
        shortcut_key_2->addItem(QString());
        shortcut_key_2->addItem(QString());
        shortcut_key_2->addItem(QString());
        shortcut_key_2->addItem(QString());
        shortcut_key_2->addItem(QString());
        shortcut_key_2->addItem(QString());
        shortcut_key_2->addItem(QString());
        shortcut_key_2->addItem(QString());
        shortcut_key_2->setObjectName("shortcut_key_2");

        horizontalLayout_2->addWidget(shortcut_key_2);


        gridLayout_5->addWidget(shortcut2_box, 2, 1, 1, 2);

        other_box = new QGroupBox(MENU);
        other_box->setObjectName("other_box");
        verticalLayout = new QVBoxLayout(other_box);
        verticalLayout->setObjectName("verticalLayout");
        other_1 = new QCheckBox(other_box);
        other_1->setObjectName("other_1");

        verticalLayout->addWidget(other_1);

        other_2 = new QCheckBox(other_box);
        other_2->setObjectName("other_2");

        verticalLayout->addWidget(other_2);


        gridLayout_5->addWidget(other_box, 1, 5, 2, 1);

        pushButton2 = new QPushButton(MENU);
        pushButton2->setObjectName("pushButton2");
        QSizePolicy sizePolicy3(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(pushButton2->sizePolicy().hasHeightForWidth());
        pushButton2->setSizePolicy(sizePolicy3);
        pushButton2->setStyleSheet(QString::fromUtf8(""));

        gridLayout_5->addWidget(pushButton2, 5, 0, 1, 6);


        gridLayout->addWidget(MENU, 0, 0, 1, 1);

        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        QSizePolicy sizePolicy4(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Preferred);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy4);
        QFont font;
        font.setBold(true);
        pushButton->setFont(font);
        pushButton->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton->setStyleSheet(QString::fromUtf8("font-size:180px;color:red;"));
        pushButton->setFlat(true);

        gridLayout->addWidget(pushButton, 1, 0, 1, 1);

        lineEdit1 = new QLineEdit(centralwidget);
        lineEdit1->setObjectName("lineEdit1");
        lineEdit1->setEchoMode(QLineEdit::EchoMode::Password);

        gridLayout->addWidget(lineEdit1, 2, 0, 1, 1);

        lineEdit2 = new QLineEdit(centralwidget);
        lineEdit2->setObjectName("lineEdit2");
        lineEdit2->setEnabled(false);

        gridLayout->addWidget(lineEdit2, 3, 0, 1, 1);

        lock->setCentralWidget(centralwidget);

        retranslateUi(lock);

        shortcut_modifier_1->setCurrentIndex(0);
        shortcut_modifier_2->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(lock);
    } // setupUi

    void retranslateUi(QMainWindow *lock)
    {
        lock->setWindowTitle(QCoreApplication::translate("lock", "Lock", nullptr));
        MENU->setTitle(QString());
        screensaver_box->setTitle(QCoreApplication::translate("lock", "\343\202\271\343\202\257\343\203\252\343\203\274\343\203\263\343\202\273\343\203\274\343\203\220\343\203\274", nullptr));
        screensaver_type->setItemText(0, QCoreApplication::translate("lock", "\343\203\226\343\203\251\343\203\263\343\202\257", nullptr));
        screensaver_type->setItemText(1, QCoreApplication::translate("lock", "\343\203\234\343\203\274\343\203\253", nullptr));

        screensaver_darkness_label->setText(QCoreApplication::translate("lock", "\346\232\227\343\201\225", nullptr));
        screensaver_start->setText(QCoreApplication::translate("lock", "\350\265\267\345\213\225", nullptr));
        screensaver_type_label->setText(QCoreApplication::translate("lock", "\343\202\277\343\202\244\343\203\227", nullptr));
        shortcut1_box->setTitle(QCoreApplication::translate("lock", "\343\203\255\343\203\203\343\202\257\343\202\267\343\203\247\343\203\274\343\203\210\343\202\253\343\203\203\343\203\210\343\202\255\343\203\274 1", nullptr));
        shortcut_enable_1->setText(QString());
        shortcut_black_1->setText(QCoreApplication::translate("lock", "\351\273\222\347\224\273\351\235\242", nullptr));
        shortcut_modifier_1->setItemText(0, QCoreApplication::translate("lock", "\350\243\205\351\243\276\343\202\255\343\203\274\343\202\222\351\201\270\346\212\236", nullptr));
        shortcut_modifier_1->setItemText(1, QCoreApplication::translate("lock", "Ctrl", nullptr));
        shortcut_modifier_1->setItemText(2, QCoreApplication::translate("lock", "Shift", nullptr));
        shortcut_modifier_1->setItemText(3, QCoreApplication::translate("lock", "Windows", nullptr));
        shortcut_modifier_1->setItemText(4, QCoreApplication::translate("lock", "Alt", nullptr));
        shortcut_modifier_1->setItemText(5, QCoreApplication::translate("lock", "Ctrl + Shift", nullptr));
        shortcut_modifier_1->setItemText(6, QCoreApplication::translate("lock", "Ctrl + Windows", nullptr));
        shortcut_modifier_1->setItemText(7, QCoreApplication::translate("lock", "Ctrl + Alt", nullptr));
        shortcut_modifier_1->setItemText(8, QCoreApplication::translate("lock", "Shift + Windows", nullptr));
        shortcut_modifier_1->setItemText(9, QCoreApplication::translate("lock", "Shift + Alt", nullptr));
        shortcut_modifier_1->setItemText(10, QCoreApplication::translate("lock", "Windows + Alt", nullptr));
        shortcut_modifier_1->setItemText(11, QCoreApplication::translate("lock", "Ctrl + Shift + Windows", nullptr));
        shortcut_modifier_1->setItemText(12, QCoreApplication::translate("lock", "Ctrl + Shift + Alt", nullptr));
        shortcut_modifier_1->setItemText(13, QCoreApplication::translate("lock", "Ctrl + Windows + Alt", nullptr));
        shortcut_modifier_1->setItemText(14, QCoreApplication::translate("lock", "Shift + Windows + Alt", nullptr));
        shortcut_modifier_1->setItemText(15, QCoreApplication::translate("lock", "Ctrl + Shift + Windows + Alt", nullptr));

        shortcut_modifier_1->setPlaceholderText(QString());
        shortcut_key_1->setItemText(0, QCoreApplication::translate("lock", "\343\202\255\343\203\274\343\201\256\351\201\270\346\212\236", nullptr));
        shortcut_key_1->setItemText(1, QCoreApplication::translate("lock", "A", nullptr));
        shortcut_key_1->setItemText(2, QCoreApplication::translate("lock", "B", nullptr));
        shortcut_key_1->setItemText(3, QCoreApplication::translate("lock", "C", nullptr));
        shortcut_key_1->setItemText(4, QCoreApplication::translate("lock", "D", nullptr));
        shortcut_key_1->setItemText(5, QCoreApplication::translate("lock", "E", nullptr));
        shortcut_key_1->setItemText(6, QCoreApplication::translate("lock", "F", nullptr));
        shortcut_key_1->setItemText(7, QCoreApplication::translate("lock", "G", nullptr));
        shortcut_key_1->setItemText(8, QCoreApplication::translate("lock", "H", nullptr));
        shortcut_key_1->setItemText(9, QCoreApplication::translate("lock", "I", nullptr));
        shortcut_key_1->setItemText(10, QCoreApplication::translate("lock", "J", nullptr));
        shortcut_key_1->setItemText(11, QCoreApplication::translate("lock", "K", nullptr));
        shortcut_key_1->setItemText(12, QCoreApplication::translate("lock", "L", nullptr));
        shortcut_key_1->setItemText(13, QCoreApplication::translate("lock", "M", nullptr));
        shortcut_key_1->setItemText(14, QCoreApplication::translate("lock", "N", nullptr));
        shortcut_key_1->setItemText(15, QCoreApplication::translate("lock", "O", nullptr));
        shortcut_key_1->setItemText(16, QCoreApplication::translate("lock", "P", nullptr));
        shortcut_key_1->setItemText(17, QCoreApplication::translate("lock", "Q", nullptr));
        shortcut_key_1->setItemText(18, QCoreApplication::translate("lock", "R", nullptr));
        shortcut_key_1->setItemText(19, QCoreApplication::translate("lock", "S", nullptr));
        shortcut_key_1->setItemText(20, QCoreApplication::translate("lock", "T", nullptr));
        shortcut_key_1->setItemText(21, QCoreApplication::translate("lock", "U", nullptr));
        shortcut_key_1->setItemText(22, QCoreApplication::translate("lock", "V", nullptr));
        shortcut_key_1->setItemText(23, QCoreApplication::translate("lock", "W", nullptr));
        shortcut_key_1->setItemText(24, QCoreApplication::translate("lock", "X", nullptr));
        shortcut_key_1->setItemText(25, QCoreApplication::translate("lock", "Y", nullptr));
        shortcut_key_1->setItemText(26, QCoreApplication::translate("lock", "Z", nullptr));

        schedule_box->setTitle(QCoreApplication::translate("lock", "\343\202\271\343\202\261\343\202\270\343\203\245\343\203\274\343\203\253(\346\214\207\345\256\232\346\231\202\345\210\27324\346\231\202\351\226\223\350\241\250\350\250\230)", nullptr));
        schedule_time_4->setDisplayFormat(QCoreApplication::translate("lock", "H:mm", nullptr));
        schedule_check_2->setText(QCoreApplication::translate("lock", "S2", nullptr));
        schedule_check_3->setText(QCoreApplication::translate("lock", "S3", nullptr));
        schedule_time_5->setDisplayFormat(QCoreApplication::translate("lock", "H:mm", nullptr));
        schedule_check_6->setText(QCoreApplication::translate("lock", "S6", nullptr));
        schedule_check_4->setText(QCoreApplication::translate("lock", "S4", nullptr));
        schedule_time_2->setDisplayFormat(QCoreApplication::translate("lock", "H:mm", nullptr));
        schedule_time_1->setDisplayFormat(QCoreApplication::translate("lock", "H:mm", nullptr));
        schedule_time_6->setDisplayFormat(QCoreApplication::translate("lock", "H:mm", nullptr));
        schedule_time_3->setDisplayFormat(QCoreApplication::translate("lock", "H:mm", nullptr));
        schedule_check_1->setText(QCoreApplication::translate("lock", "S1", nullptr));
        schedule_check_5->setText(QCoreApplication::translate("lock", "S5", nullptr));
        shortcut2_box->setTitle(QCoreApplication::translate("lock", "\343\203\255\343\203\203\343\202\257\343\202\267\343\203\247\343\203\274\343\203\210\343\202\253\343\203\203\343\203\210\343\202\255\343\203\274 2", nullptr));
        shortcut_enable_2->setText(QString());
        shortcut_black_2->setText(QCoreApplication::translate("lock", "\351\273\222\347\224\273\351\235\242", nullptr));
        shortcut_modifier_2->setItemText(0, QCoreApplication::translate("lock", "\350\243\205\351\243\276\343\202\255\343\203\274\343\202\222\351\201\270\346\212\236", nullptr));
        shortcut_modifier_2->setItemText(1, QCoreApplication::translate("lock", "Ctrl", nullptr));
        shortcut_modifier_2->setItemText(2, QCoreApplication::translate("lock", "Shift", nullptr));
        shortcut_modifier_2->setItemText(3, QCoreApplication::translate("lock", "Windows", nullptr));
        shortcut_modifier_2->setItemText(4, QCoreApplication::translate("lock", "Alt", nullptr));
        shortcut_modifier_2->setItemText(5, QCoreApplication::translate("lock", "Ctrl + Shift", nullptr));
        shortcut_modifier_2->setItemText(6, QCoreApplication::translate("lock", "Ctrl + Windows", nullptr));
        shortcut_modifier_2->setItemText(7, QCoreApplication::translate("lock", "Ctrl + Alt", nullptr));
        shortcut_modifier_2->setItemText(8, QCoreApplication::translate("lock", "Shift + Windows", nullptr));
        shortcut_modifier_2->setItemText(9, QCoreApplication::translate("lock", "Shift + Alt", nullptr));
        shortcut_modifier_2->setItemText(10, QCoreApplication::translate("lock", "Windows + Alt", nullptr));
        shortcut_modifier_2->setItemText(11, QCoreApplication::translate("lock", "Ctrl + Shift + Windows", nullptr));
        shortcut_modifier_2->setItemText(12, QCoreApplication::translate("lock", "Ctrl + Shift + Alt", nullptr));
        shortcut_modifier_2->setItemText(13, QCoreApplication::translate("lock", "Ctrl + Windows + Alt", nullptr));
        shortcut_modifier_2->setItemText(14, QCoreApplication::translate("lock", "Shift + Windows + Alt", nullptr));
        shortcut_modifier_2->setItemText(15, QCoreApplication::translate("lock", "Ctrl + Shift + Windows + Alt", nullptr));

        shortcut_modifier_2->setPlaceholderText(QString());
        shortcut_key_2->setItemText(0, QCoreApplication::translate("lock", "\343\202\255\343\203\274\343\201\256\351\201\270\346\212\236", nullptr));
        shortcut_key_2->setItemText(1, QCoreApplication::translate("lock", "A", nullptr));
        shortcut_key_2->setItemText(2, QCoreApplication::translate("lock", "B", nullptr));
        shortcut_key_2->setItemText(3, QCoreApplication::translate("lock", "C", nullptr));
        shortcut_key_2->setItemText(4, QCoreApplication::translate("lock", "D", nullptr));
        shortcut_key_2->setItemText(5, QCoreApplication::translate("lock", "E", nullptr));
        shortcut_key_2->setItemText(6, QCoreApplication::translate("lock", "F", nullptr));
        shortcut_key_2->setItemText(7, QCoreApplication::translate("lock", "G", nullptr));
        shortcut_key_2->setItemText(8, QCoreApplication::translate("lock", "H", nullptr));
        shortcut_key_2->setItemText(9, QCoreApplication::translate("lock", "I", nullptr));
        shortcut_key_2->setItemText(10, QCoreApplication::translate("lock", "J", nullptr));
        shortcut_key_2->setItemText(11, QCoreApplication::translate("lock", "K", nullptr));
        shortcut_key_2->setItemText(12, QCoreApplication::translate("lock", "L", nullptr));
        shortcut_key_2->setItemText(13, QCoreApplication::translate("lock", "M", nullptr));
        shortcut_key_2->setItemText(14, QCoreApplication::translate("lock", "N", nullptr));
        shortcut_key_2->setItemText(15, QCoreApplication::translate("lock", "O", nullptr));
        shortcut_key_2->setItemText(16, QCoreApplication::translate("lock", "P", nullptr));
        shortcut_key_2->setItemText(17, QCoreApplication::translate("lock", "Q", nullptr));
        shortcut_key_2->setItemText(18, QCoreApplication::translate("lock", "R", nullptr));
        shortcut_key_2->setItemText(19, QCoreApplication::translate("lock", "S", nullptr));
        shortcut_key_2->setItemText(20, QCoreApplication::translate("lock", "T", nullptr));
        shortcut_key_2->setItemText(21, QCoreApplication::translate("lock", "U", nullptr));
        shortcut_key_2->setItemText(22, QCoreApplication::translate("lock", "V", nullptr));
        shortcut_key_2->setItemText(23, QCoreApplication::translate("lock", "W", nullptr));
        shortcut_key_2->setItemText(24, QCoreApplication::translate("lock", "X", nullptr));
        shortcut_key_2->setItemText(25, QCoreApplication::translate("lock", "Y", nullptr));
        shortcut_key_2->setItemText(26, QCoreApplication::translate("lock", "Z", nullptr));

        other_box->setTitle(QCoreApplication::translate("lock", "\343\201\235\343\201\256\344\273\226", nullptr));
        other_1->setText(QCoreApplication::translate("lock", "\345\206\215\350\265\267\345\213\225\346\231\202\343\201\253\343\203\255\343\203\203\343\202\257\343\202\222\347\266\231\347\266\232", nullptr));
        other_2->setText(QCoreApplication::translate("lock", "PC\350\265\267\345\213\225\346\231\202\343\201\253\343\201\223\343\201\256\343\202\242\343\203\227\343\203\252\343\202\222\346\234\200\345\260\217\345\214\226\347\212\266\346\205\213\343\201\247\350\265\267\345\213\225\n"
"(\346\234\211\345\212\271\343\201\247\343\201\257\343\201\252\343\201\204\343\201\250PC\350\265\267\345\213\225\346\231\202\343\201\253\346\213\241\345\274\265\346\251\237\350\203\275\343\201\214\345\213\225\344\275\234\343\201\227\343\201\252\343\201\204)", nullptr));
        pushButton2->setText(QCoreApplication::translate("lock", "WindowHide", nullptr));
        pushButton->setText(QCoreApplication::translate("lock", "Unlocked", nullptr));
        lineEdit1->setInputMask(QString());
        lineEdit1->setPlaceholderText(QCoreApplication::translate("lock", "Password", nullptr));
    } // retranslateUi

};

namespace Ui {
    class lock: public Ui_lock {};
} // namespace Ui

QT_END_NAMESPACE

#endif // LOCK_H
