#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <functional>
#include <random>
#include <QtCore/QObject>
#include <QtCore/QTimer>
#include <QtGui/QKeyEvent>
#include <QtWidgets/QWidget>
#include <QtWidgets/QLineEdit>
#include "ui_typing.h"

std::vector<std::string> text;
std::string currentText;
Ui::Typing ui;
int score=0;
void scoreChange(int i);
static int textSize;

int random(const int& up) {
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> distribution(0, up);
	return distribution(gen);
}

class T_LineEditClass: public QLineEdit {
protected:
    void keyPressEvent(QKeyEvent *event) override {
        if (event->key() == Qt::Key_Backspace || event->key() == Qt::Key_Delete) {
			scoreChange(-1);
			QLineEdit::keyPressEvent(event);
        } else if (event->key() == Qt::Key_Escape) {
			this->setText("");
			scoreChange(-1);
		} else QLineEdit::keyPressEvent(event);
	}
};
T_LineEditClass* tLineEdit = nullptr;

void scoreChange(int i) {
		score+=i;
		ui.scoreChange->setText(QString::fromStdString(std::to_string(i)));
		if (i>0) {
			ui.scoreChange->setStyleSheet("qproperty-alignment: AlignCenter; color: blue; font-size: 10;");
			ui.text->setStyleSheet("qproperty-alignment: AlignCenter; font-size: 50px; color: blue;");
		} else {
			ui.scoreChange->setStyleSheet("qproperty-alignment: AlignCenter; color: red; font-size: 10;");
			ui.text->setStyleSheet("qproperty-alignment: AlignCenter; font-size: 50px; color: red;");
		}
		ui.score->display(score);
		QTimer::singleShot(500, [] {ui.text->setStyleSheet("qproperty-alignment: AlignCenter; font-size: 50px; color: black;");});
		QTimer::singleShot(1000, [] {ui.scoreChange->setText("");});
	}

void enter() {
	if (tLineEdit->text()==QString::fromStdString(currentText)) {
		scoreChange(10);
		currentText=text[random(textSize)];
		ui.text->setText(QString::fromStdString(currentText));
		tLineEdit->setText("");
	} else {
		scoreChange(-3);
	}
}

std::string hash_file(const std::string& file_path) {
    std::ifstream file(file_path);
    if (!file.is_open()) {
        throw std::runtime_error("Failed to open file");
    }

    std::stringstream buffer;
    buffer << file.rdbuf();
    std::string file_contents = buffer.str();

    std::hash<std::string> hasher;
    std::size_t hash_value = hasher(file_contents);

    std::stringstream ss;
    ss << std::hex << hash_value;
    return ss.str();
}

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    QWidget	widget;
    ui.setupUi(&widget);

	tLineEdit = new T_LineEditClass;

	std::string dbf="typing.db";
	ui.label_hash->setText("DataBase-Hash: " + QString::fromStdString(hash_file(dbf)));
	std::ifstream file(dbf);
	std::string line;
	while (std::getline(file, line)) text.push_back(line);
	file.close();
	textSize = text.size()-1;

	ui.gridLayout->addWidget(tLineEdit, 1,0,1,-1);
	QObject::connect(tLineEdit, &QLineEdit::returnPressed, enter);
	tLineEdit->setFocus();
	
	// startup
	currentText=text[random(text.size()-1)];
	ui.text->setText(QString::fromStdString(currentText));
	

	widget.show();
	return app.exec();
}