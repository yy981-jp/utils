/********************************************************************************
** Form generated from reading UI file 'shootingLauncher.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef SHOOTINGLAUNCHER_H
#define SHOOTINGLAUNCHER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SL
{
public:
    QGridLayout *gridLayout;
    QPushButton *button;

    void setupUi(QWidget *SL)
    {
        if (SL->objectName().isEmpty())
            SL->setObjectName("SL");
        SL->resize(758, 616);
        SL->setStyleSheet(QString::fromUtf8(""));
        gridLayout = new QGridLayout(SL);
        gridLayout->setObjectName("gridLayout");
        button = new QPushButton(SL);
        button->setObjectName("button");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(button->sizePolicy().hasHeightForWidth());
        button->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(100);
        button->setFont(font);
        button->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        button->setStyleSheet(QString::fromUtf8(""));
        button->setAutoDefault(false);
        button->setFlat(false);

        gridLayout->addWidget(button, 0, 0, 1, 1);


        retranslateUi(SL);

        button->setDefault(true);


        QMetaObject::connectSlotsByName(SL);
    } // setupUi

    void retranslateUi(QWidget *SL)
    {
        SL->setWindowTitle(QCoreApplication::translate("SL", "ShootingLauncher", nullptr));
        button->setText(QCoreApplication::translate("SL", "\343\202\262\343\203\274\343\203\240\343\202\222\350\265\267\345\213\225", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SL: public Ui_SL {};
} // namespace Ui

QT_END_NAMESPACE

#endif // SHOOTINGLAUNCHER_H
