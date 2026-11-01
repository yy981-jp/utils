#include <QtCore/QObject>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QWidget>
#include <QtWidgets/QLabel>
#include <random>
#include "ui_subwindow.h"


void gamestart(QWidget& window, QWidget& subwindow, QGridLayout* layout, int& size, int& answer, int& gamecount);
void gameclear(QWidget& subwindow);
void gamegiveup(QWidget& window, QWidget& subwindow, int& gamecount);

int gamecount=0;

int random(const int& up) {
    std::random_device rd;
    std::mt19937_64 gen(rd());
    std::uniform_int_distribution<int> dis(0, up);
    return dis(gen);
}

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    QWidget window;
    QWidget subwindow_w;
    Ui::TreasureHunt_SubWindow subwindow;
    subwindow.setupUi(&subwindow_w);

    QGridLayout *layout = new QGridLayout(&window);
	layout->setSpacing(0);
    int size = 20;
    int answer = random((size * size) - 1);

    QObject::connect(subwindow.GO, &QPushButton::clicked, [&]{ gamestart(window, subwindow_w, layout, size, answer, gamecount); });
    QObject::connect(subwindow.giveup, &QPushButton::clicked, [&]{ gamegiveup(window, subwindow_w, gamecount); });

    window.show();
    subwindow_w.show();
    return app.exec();
}

void gamestart(QWidget& window, QWidget& subwindow, QGridLayout* layout, int& size, int& answer, int& gamecount) {
	gamecount=0;
    subwindow.findChild<QPushButton*>("GO")->setEnabled(false);
    subwindow.findChild<QPushButton*>("giveup")->setEnabled(true);
    subwindow.findChild<QLabel*>("label_clear")->setText("");
    QList<QPushButton *> allButtons = window.findChildren<QPushButton *>();
    for (QPushButton *button : allButtons) {
        delete button;
    }

    size = subwindow.findChild<QSpinBox*>("spinbox")->value();
    answer = random(size*size);
	subwindow.findChild<QLCDNumber*>("difficulty")->display(size);

    const int buttonsPerRow = size;
    const int rowCount = size;
    for (int row = 0; row < rowCount; ++row) {
        for (int col = 0; col < buttonsPerRow; ++col) {
            QPushButton *button = new QPushButton("-");
            button->setMinimumSize(30, 20);
			button->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
            layout->addWidget(button, row, col);
            int ButtonID = row * buttonsPerRow + col;
            button->setObjectName(QString::fromStdString("B" + std::to_string(ButtonID)));
            QObject::connect(button, &QPushButton::clicked, [ButtonID, answer, button, &window, &subwindow, &gamecount] {
                if (ButtonID != answer) {
                    button->setStyleSheet("background-color: red;");
					gamecount++;subwindow.findChild<QLCDNumber*>("count")->display(gamecount);					
			   } else {
                    button->setStyleSheet("background-color: green;");
					gameclear(subwindow);
				}
            });
        }
    }
}

void gameclear(QWidget& subwindow) {
    subwindow.findChild<QPushButton*>("GO")->setEnabled(true);
    subwindow.findChild<QPushButton*>("giveup")->setEnabled(false);
    subwindow.findChild<QLabel*>("label_clear")->setText("GameClear!!! GOを押して進む");
}

void gamegiveup(QWidget& window, QWidget& subwindow, int& gamecount) {
    QList<QPushButton *> allButtons = window.findChildren<QPushButton *>();
    for (QPushButton *button : allButtons) {
        gamecount--;
		button->click();
    }
    subwindow.findChild<QPushButton*>("GO")->setEnabled(true);
    subwindow.findChild<QPushButton*>("giveup")->setEnabled(false);
    subwindow.findChild<QLabel*>("label_clear")->setText("giveup GOを押して進む");
}
