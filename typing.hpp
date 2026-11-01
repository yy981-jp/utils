/********************************************************************************
** Form generated from reading UI file 'typing.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef TYPING_H
#define TYPING_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Typing
{
public:
    QGridLayout *gridLayout;
    QLabel *label_hash;
    QLabel *text;
    QLabel *label;
    QLabel *scoreChange;
    QLCDNumber *type;
    QLabel *label_2;
    QLCDNumber *score;

    void setupUi(QWidget *Typing)
    {
        if (Typing->objectName().isEmpty())
            Typing->setObjectName("Typing");
        Typing->resize(800, 250);
        gridLayout = new QGridLayout(Typing);
        gridLayout->setObjectName("gridLayout");
        label_hash = new QLabel(Typing);
        label_hash->setObjectName("label_hash");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_hash->sizePolicy().hasHeightForWidth());
        label_hash->setSizePolicy(sizePolicy);

        gridLayout->addWidget(label_hash, 5, 0, 1, 1);

        text = new QLabel(Typing);
        text->setObjectName("text");
        sizePolicy.setHeightForWidth(text->sizePolicy().hasHeightForWidth());
        text->setSizePolicy(sizePolicy);
        text->setStyleSheet(QString::fromUtf8("qproperty-alignment: AlignCenter; font-size: 50px;"));
        text->setWordWrap(true);

        gridLayout->addWidget(text, 7, 0, 1, 4);

        label = new QLabel(Typing);
        label->setObjectName("label");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Maximum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(label, 3, 0, 1, 4);

        scoreChange = new QLabel(Typing);
        scoreChange->setObjectName("scoreChange");
        sizePolicy1.setHeightForWidth(scoreChange->sizePolicy().hasHeightForWidth());
        scoreChange->setSizePolicy(sizePolicy1);
        scoreChange->setStyleSheet(QString::fromUtf8("qproperty-alignment: AlignCenter; color:red;"));

        gridLayout->addWidget(scoreChange, 6, 0, 1, 4);

        type = new QLCDNumber(Typing);
        type->setObjectName("type");
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Maximum, QSizePolicy::Policy::Minimum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(type->sizePolicy().hasHeightForWidth());
        type->setSizePolicy(sizePolicy2);
        type->setMinimumSize(QSize(150, 0));
        type->setMaximumSize(QSize(16777215, 30));
        QFont font;
        font.setPointSize(5);
        type->setFont(font);
        type->setContextMenuPolicy(Qt::ContextMenuPolicy::DefaultContextMenu);
        type->setStyleSheet(QString::fromUtf8(""));
        type->setSmallDecimalPoint(false);
        type->setDigitCount(10);
        type->setMode(QLCDNumber::Mode::Dec);
        type->setSegmentStyle(QLCDNumber::SegmentStyle::Filled);

        gridLayout->addWidget(type, 5, 1, 1, 1);

        label_2 = new QLabel(Typing);
        label_2->setObjectName("label_2");
        label_2->setMaximumSize(QSize(50, 16777215));

        gridLayout->addWidget(label_2, 5, 2, 1, 1);

        score = new QLCDNumber(Typing);
        score->setObjectName("score");
        sizePolicy2.setHeightForWidth(score->sizePolicy().hasHeightForWidth());
        score->setSizePolicy(sizePolicy2);
        score->setMinimumSize(QSize(150, 0));
        score->setMaximumSize(QSize(16777215, 30));
        score->setFont(font);
        score->setContextMenuPolicy(Qt::ContextMenuPolicy::DefaultContextMenu);
        score->setStyleSheet(QString::fromUtf8(""));
        score->setSmallDecimalPoint(false);
        score->setDigitCount(10);
        score->setMode(QLCDNumber::Mode::Dec);
        score->setSegmentStyle(QLCDNumber::SegmentStyle::Filled);

        gridLayout->addWidget(score, 5, 3, 1, 1);


        retranslateUi(Typing);

        QMetaObject::connectSlotsByName(Typing);
    } // setupUi

    void retranslateUi(QWidget *Typing)
    {
        Typing->setWindowTitle(QCoreApplication::translate("Typing", "Typing", nullptr));
        label_hash->setText(QCoreApplication::translate("Typing", "<html><head/><body><p align=\"center\">DBHash</p></body></html>", nullptr));
        text->setText(QCoreApplication::translate("Typing", "Text", nullptr));
        label->setText(QCoreApplication::translate("Typing", "<html><head/><body><p align=\"center\">\343\202\242\343\203\227\343\203\252\351\226\213\347\231\272\343\203\273\344\274\201\347\224\273: \345\261\261\346\234\254 ||| \343\203\207\343\203\274\343\202\277\343\203\231\343\203\274\343\202\271: \346\203\205\345\240\261\346\212\200\350\241\223\351\203\25038\345\233\236\347\224\237</p></body></html>", nullptr));
        scoreChange->setText(QString());
        label_2->setText(QCoreApplication::translate("Typing", "<html><head/><body><p align=\"right\"><span style=\" font-weight:700;\">Score:</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Typing: public Ui_Typing {};
} // namespace Ui

QT_END_NAMESPACE

#endif // TYPING_H
