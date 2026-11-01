#include <iostream>
#include <vector>
#include <filesystem>
#include <QtCore/QObject>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QGridlayout>
#include <QtWidgets/QWidget>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMessageBox>
#include <yy981/random.h>
#include ".h/qt/thg2.h"

Ui::thg2 ui;
int dif = -1;
int size = -1;
int count = 0;
bool clickable(true), giveuped(false);
inline void setInfo(const char* str) {ui.info->setText(QString::fromLocal8Bit(str));}
std::string path_d;

void delete_f(const std::string& directory) {
	std::filesystem::path dirPath(directory);

	if (!std::filesystem::exists(dirPath) || !std::filesystem::is_directory(dirPath)) {
		std::cerr << "指定されたパスは存在しないか、ディレクトリではありません: " << directory << std::endl;
		return;
	}

	// 再帰的に探索し、最初のファイルを削除したら終了
	for (const auto& entry : std::filesystem::recursive_directory_iterator(dirPath)) {
		if (std::filesystem::is_regular_file(entry.path())) {
			try {
				std::filesystem::remove(entry.path());
				std::cout << "削除: " << entry.path() << std::endl;
			} catch (const std::filesystem::filesystem_error& e) {
				std::cerr << "削除失敗: " << entry.path() << " - " << e.what() << std::endl;
			}
			return; // 1つ削除したら関数を抜ける
		}
	}

	std::cout << "削除するファイルがありません: " << directory << std::endl;
}

bool warning(const char* str) {
	QMessageBox msgBox;
	msgBox.setWindowTitle(QString::fromLocal8Bit("確認"));
	msgBox.setText(QString::fromLocal8Bit(str));
	msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
	msgBox.setDefaultButton(QMessageBox::Yes);
	switch (msgBox.exec()) {
		case QMessageBox::Yes: return true;
		case QMessageBox::No: return false;
	}
	return false;
}

void end(bool gameClear);

class PB;
PB* answer = nullptr;
class PB: public QPushButton {
Q_OBJECT
public slots:
	void open() {
		if (opened||!clickable) return;
		opened = true;
		
		if (this == answer) {
			setStyleSheet("background-color: green;");
			if (!giveuped) end(true);
		} else {
			setStyleSheet("background-color: red;");
			if (!giveuped) {
				count++;
				ui.inf_count->display(count);
				delete_f(path_d);
			}
		}
	}
private:
	bool opened = false;
};
std::vector<PB*> list;


void clear() {
	if (list.size() == 0) return;
	count = 0;
	ui.inf_count->display(count);
	for (PB* c: list) {
		delete c;
	}
	list.clear();
}

void start() {
	setInfo("-----");
	dif = ui.set_dif->value();
	size = dif*dif;
	clickable = true;
	if (list.size() != 0) clear();
	list.reserve(size);

	const int buttonsPerRow = dif;
	const int rowCount = dif;
	for (int row = 10; row < rowCount+10; ++row) {
		for (int col = 10; col < buttonsPerRow+10; ++col) {
			PB* current = new PB;
			current->setMinimumSize(30, 20);
			current->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
			QObject::connect(current, &QPushButton::clicked, current, &PB::open);
			ui.layout->addWidget(current, row, col);  // ここでレイアウトに追加
			list.emplace_back(current);
		}
	}
	// std::cout << "DEBUG::: size:" << size << " dif:" << dif << " listSize:" << list.size() << "\n";
	if (size == 1) answer = list[0]; else answer = list[randomNum(0, size-1)];
	if (!answer) throw std::runtime_error("answer = nullptr");
	
	// control disable
	ui.giveup->setStyleSheet("background-color: tomato; color: white");
    ui.start->setStyleSheet("");
	ui.set_dif->setEnabled(false);
	ui.start->setEnabled(false);
	ui.clear->setEnabled(false);
	ui.giveup->setEnabled(true);
}

void end(bool gameClear = false) {
	if (gameClear) setInfo("ゲームクリア");
	clickable = false;
	
	// control enable
    ui.start->setStyleSheet("background-color: dodgerblue; color: white;");
    ui.giveup->setStyleSheet("");
	ui.set_dif->setEnabled(true);
	ui.start->setEnabled(true);
	ui.clear->setEnabled(true);
	ui.giveup->setEnabled(false);
}

void giveup() {
	if (!warning("本当に諦めますか?")) return;
	setInfo("すべてのボタンを開けます");
	giveuped = true;
	for (PB* c: list) c->open();
	giveuped = false;
	end();
}


int main(int argc, char *argv[]) {
	path_d = argv[1];
	QApplication app(argc, argv);
	QWidget window;
	ui.setupUi(&window);
	ui.layout->setSpacing(0);
	// connect
	QObject::connect(ui.start, &QPushButton::clicked, start);
	QObject::connect(ui.giveup, &QPushButton::clicked, giveup);
	QObject::connect(ui.clear, &QPushButton::clicked, []{
		setInfo("-----");
		clear();
	});
	
	setInfo("下にある欄に辺の長さを入力して\nSTARTを押してください");


	window.showFullScreen();
	return app.exec();
}

#include "danger_thg2.moc"