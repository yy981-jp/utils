/********************************************************************************
** Form generated from reading UI file 'thg2.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef THG2_H
#define THG2_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_thg2
{
public:
    QGridLayout *gridLayout_2;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QPushButton *giveup;
    QPushButton *start;
    QLabel *inf_count_l;
    QFrame *line;
    QLCDNumber *inf_count;
    QSpinBox *set_dif;
    QSpacerItem *verticalSpacer;
    QLabel *info;
    QPushButton *clear;
    QGridLayout *layout;

    void setupUi(QWidget *thg2)
    {
        if (thg2->objectName().isEmpty())
            thg2->setObjectName("thg2");
        thg2->resize(800, 600);
        gridLayout_2 = new QGridLayout(thg2);
        gridLayout_2->setObjectName("gridLayout_2");
        groupBox = new QGroupBox(thg2);
        groupBox->setObjectName("groupBox");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy);
        groupBox->setMaximumSize(QSize(200, 16777215));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName("gridLayout");
        giveup = new QPushButton(groupBox);
        giveup->setObjectName("giveup");
        giveup->setStyleSheet(QString::fromUtf8("background-color: tomato; color: white"));

        gridLayout->addWidget(giveup, 3, 0, 1, 2);

        start = new QPushButton(groupBox);
        start->setObjectName("start");
        QFont font;
        font.setBold(true);
        start->setFont(font);
        start->setStyleSheet(QString::fromUtf8("background-color: dodgerblue; color: white;"));
        start->setCheckable(false);

        gridLayout->addWidget(start, 2, 0, 1, 2);

        inf_count_l = new QLabel(groupBox);
        inf_count_l->setObjectName("inf_count_l");
        QFont font1;
        font1.setPointSize(12);
        font1.setBold(true);
        inf_count_l->setFont(font1);

        gridLayout->addWidget(inf_count_l, 5, 0, 1, 2);

        line = new QFrame(groupBox);
        line->setObjectName("line");
        line->setFrameShape(QFrame::Shape::VLine);
        line->setFrameShadow(QFrame::Shadow::Sunken);

        gridLayout->addWidget(line, 0, 2, 10, 1);

        inf_count = new QLCDNumber(groupBox);
        inf_count->setObjectName("inf_count");
        inf_count->setStyleSheet(QString::fromUtf8("background-color: green"));
        inf_count->setDigitCount(10);

        gridLayout->addWidget(inf_count, 6, 0, 1, 2);

        set_dif = new QSpinBox(groupBox);
        set_dif->setObjectName("set_dif");
        set_dif->setMouseTracking(false);
        set_dif->setTabletTracking(false);
        set_dif->setMinimum(1);
        set_dif->setMaximum(999999999);
        set_dif->setSingleStep(1);
        set_dif->setValue(20);

        gridLayout->addWidget(set_dif, 1, 0, 1, 2);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer, 7, 0, 1, 1);

        info = new QLabel(groupBox);
        info->setObjectName("info");
        info->setStyleSheet(QString::fromUtf8(""));
        info->setFrameShape(QFrame::Shape::WinPanel);
        info->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout->addWidget(info, 0, 0, 1, 2);

        clear = new QPushButton(groupBox);
        clear->setObjectName("clear");

        gridLayout->addWidget(clear, 8, 0, 1, 2);


        gridLayout_2->addWidget(groupBox, 0, 0, 1, 1);

        layout = new QGridLayout();
        layout->setObjectName("layout");

        gridLayout_2->addLayout(layout, 0, 1, 1, 1);


        retranslateUi(thg2);
        QObject::connect(set_dif, &QSpinBox::editingFinished, start, qOverload<>(&QPushButton::animateClick));

        QMetaObject::connectSlotsByName(thg2);
    } // setupUi

    void retranslateUi(QWidget *thg2)
    {
        thg2->setWindowTitle(QCoreApplication::translate("thg2", "TreasureHuntGui_ver2", nullptr));
        groupBox->setTitle(QCoreApplication::translate("thg2", "\346\223\215\344\275\234\347\233\244", nullptr));
        giveup->setText(QCoreApplication::translate("thg2", "GiveUp", nullptr));
        start->setText(QCoreApplication::translate("thg2", "START", nullptr));
        inf_count_l->setText(QCoreApplication::translate("thg2", "\343\202\253\343\202\246\343\203\263\343\203\210:", nullptr));
        info->setText(QCoreApplication::translate("thg2", "-----", nullptr));
        clear->setText(QCoreApplication::translate("thg2", "\346\216\203\351\231\244", nullptr));
    } // retranslateUi

};

namespace Ui {
    class thg2: public Ui_thg2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // THG2_H
