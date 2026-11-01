#include <iostream>
#include <string>
#include <windows.h>
#include "ui_lock.h"
#include <QtCore/QObject>
#include <QtCore/QString>
#include <QtCore/QThread>
#include <QtWidgets/QWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QStyleFactory>
#include <QtGui/QCloseEvent>
#include <fstream>
#include <filesystem>
#include <chrono>
#include <thread>



Ui::lock ui;
void lock();
HHOOK keyboardHook;
HHOOK TouchHook;
LRESULT CALLBACK KeyboardProc(int nCode, WPARAM wParam, LPARAM lParam);
HWND hwnd;
bool statusl=false;
std::vector<std::string>savedata;
std::string password="pass";
const std::string appdataP = std::string(std::getenv("localappdata")) + "/system/lock";



class MainWindow : public QMainWindow {
Q_OBJECT
public:
	MainWindow(bool* statusl, QMainWindow* parent=nullptr): QMainWindow(parent), status_m(statusl) {}
protected:
    void closeEvent(QCloseEvent *event) override {event->ignore();}
    void changeEvent(QEvent* event) override {
        if (event->type() == QEvent::ActivationChange) {
            if (*status_m&&!isActiveWindow()) {setFocus();LockWorkStation();}
        } else QMainWindow::changeEvent(event);
    }
private: bool* status_m;
};
MainWindow* window = nullptr;

/*
class ssBlack: public QWidget {
    Q_OBJECT

public:
    ssBlack(QWidget *parent = nullptr) : QWidget(parent) {setStyleSheet("background-color: black;");}
protected:
    void mousePressEvent(QMouseEvent *event) override {
		std::cout << "blackWidgetCliked\n";
		if (event->button() == Qt::LeftButton) this->deleteLater();
	}
};

class SignalSlot: public QObject {
Q_OBJECT
signals:
	void screenSaverSignal(int type);
public slots:
	void screenSaverSlot(int type) {
		if (type==0) {
			ssBlack blackWidget;
			window->setCentralWidget(&blackWidget);
		}
	}
};
SignalSlot signalSlot;
*/

void lockHotkey(int s) {
	// if (s==1) {
		// std::cout << "lockHotkey\n";
		// if (ui.shortcut_black_1->isChecked()) emit signalSlot.screenSaverSignal(0);
		if (!statusl) lock();
	// } else {
		
	// }
}

void setHotkey() {
	if (ui.shortcut_enable_1->isChecked() && ui.shortcut_modifier_1->currentIndex()!=0 && ui.shortcut_key_1->currentIndex()!=0) {
		UINT modifiers=0;
		UINT vkCode = ui.shortcut_key_1->currentText().toStdString()[0];
		switch(ui.shortcut_modifier_1->currentIndex()) {
			case 1: modifiers = MOD_CONTROL; break;
			case 2: modifiers = MOD_SHIFT; break;
			case 3: modifiers = MOD_WIN; break;
			case 4: modifiers = MOD_ALT; break;
			case 5: modifiers = MOD_CONTROL | MOD_SHIFT; break;
			case 6: modifiers = MOD_CONTROL | MOD_WIN; break;
			case 7: modifiers = MOD_CONTROL | MOD_ALT; break;
			case 8: modifiers = MOD_SHIFT | MOD_WIN; break;
			case 9: modifiers = MOD_SHIFT | MOD_ALT; break;
			case 10: modifiers = MOD_WIN | MOD_ALT; break;
			case 11: modifiers = MOD_CONTROL | MOD_SHIFT | MOD_WIN; break;
			case 12: modifiers = MOD_CONTROL | MOD_SHIFT | MOD_ALT; break;
			case 13: modifiers = MOD_CONTROL | MOD_WIN | MOD_ALT; break;
			case 14: modifiers = MOD_SHIFT | MOD_WIN | MOD_ALT; break;
			case 15: modifiers = MOD_CONTROL | MOD_SHIFT | MOD_WIN | MOD_ALT; break;
		}
		RegisterHotKey(nullptr, 98101, modifiers, vkCode);
	} else UnregisterHotKey(nullptr, 98101);
	
	if (ui.shortcut_enable_2->isChecked() && ui.shortcut_modifier_2->currentIndex()!=0 && ui.shortcut_key_2->currentIndex()!=0) {
		UINT modifiers=0;
		UINT vkCode = ui.shortcut_key_2->currentText().toStdString()[0];
		switch(ui.shortcut_modifier_1->currentIndex()) {
			case 1: modifiers = MOD_CONTROL; break;
			case 2: modifiers = MOD_SHIFT; break;
			case 3: modifiers = MOD_WIN; break;
			case 4: modifiers = MOD_ALT; break;
			case 5: modifiers = MOD_CONTROL | MOD_SHIFT; break;
			case 6: modifiers = MOD_CONTROL | MOD_WIN; break;
			case 7: modifiers = MOD_CONTROL | MOD_ALT; break;
			case 8: modifiers = MOD_SHIFT | MOD_WIN; break;
			case 9: modifiers = MOD_SHIFT | MOD_ALT; break;
			case 10: modifiers = MOD_WIN | MOD_ALT; break;
			case 11: modifiers = MOD_CONTROL | MOD_SHIFT | MOD_WIN; break;
			case 12: modifiers = MOD_CONTROL | MOD_SHIFT | MOD_ALT; break;
			case 13: modifiers = MOD_CONTROL | MOD_WIN | MOD_ALT; break;
			case 14: modifiers = MOD_SHIFT | MOD_WIN | MOD_ALT; break;
			case 15: modifiers = MOD_CONTROL | MOD_SHIFT | MOD_WIN | MOD_ALT; break;
		}
		RegisterHotKey(nullptr, 98102, modifiers, vkCode);
	} else UnregisterHotKey(nullptr, 98102);
}

inline void writeStatus() {
	if (!std::filesystem::exists(appdataP)) std::filesystem::create_directories(appdataP);
	std::ofstream statusF(appdataP + "/status.dat",std::ios_base::binary);
	statusF << statusl;
}

void unlock() {
    ui.lineEdit1->setText("");
    ui.lineEdit2->setEnabled(false);
    ui.pushButton->setEnabled(true);
    ui.pushButton->setStyleSheet("font-size:180px;color:red;");
    ui.pushButton->setText("Unlocked");
	ui.pushButton->setEnabled(true);
    ui.pushButton2->setEnabled(true);
	
	ui.schedule_box->setEnabled(true);
	ui.shortcut1_box->setEnabled(true);
	ui.shortcut2_box->setEnabled(true);
	ui.other_box->setEnabled(true);
	
	ui.lineEdit1->setFocus();
    SetWindowPos(hwnd, HWND_NOTOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);
    UnhookWindowsHookEx(keyboardHook);
	// UnhookWindowsHookEx(TouchHook);
    statusl=false;
	writeStatus();
}

void lock() {
    ui.lineEdit1->setText("");
    ui.lineEdit2->setEnabled(true);
    ui.pushButton->setStyleSheet("font-size:180px;color:#66BB6A;");
    ui.pushButton->setText("Locked");
	ui.pushButton->setEnabled(false);
    ui.pushButton2->setEnabled(false);
	
	ui.schedule_box->setEnabled(false);
	ui.shortcut1_box->setEnabled(false);
	ui.shortcut2_box->setEnabled(false);
	ui.other_box->setEnabled(false);
	
    ui.lineEdit1->setFocus();
    SetWindowPos(hwnd, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);
    keyboardHook = SetWindowsHookEx(WH_KEYBOARD_LL, KeyboardProc, NULL, 0);
	// TouchHook = SetWindowsHookEx(WH_GETMESSAGE, TouchProc, NULL, 0);
    statusl=true;
	writeStatus();
}

bool string_to_bool(std::string& str) {if (str=="true") return true; return false;}

class Schedule: public QThread {
Q_OBJECT
signals:
	void lockSignal();
	void unlockSignal();

public slots:
	void lockSlot() {lock();}
	void unlockSlot() {unlock();}

public:
	void run() override {
		int c_time;
		// std::cout << "Background.Schedule.systemBegin\n";
		while(true) {
			time_t currentTime = time(nullptr);
			std::tm localTime = *std::localtime(&currentTime);
			c_time = (localTime.tm_hour*100)+(localTime.tm_min);
				// std::cout << "ui.schedule_check_1->checkState(): " << ui.schedule_check_1->checkState() << "\n";
			if (ui.schedule_check_1->checkState()!=Qt::Unchecked) if (c_time == std::stoi(
				(savedata[7].find(":")==std::string::npos)? savedata[7]:savedata[7].replace(savedata[7].find(":"),1,""))) {
					switch(ui.schedule_check_1->checkState()) {
						case Qt::PartiallyChecked: if (!statusl) emit lockSignal(); break;
						case Qt::Checked: if (statusl) emit unlockSignal(); break;
					}
				}
			if (ui.schedule_check_2->checkState()!=Qt::Unchecked) if (c_time == std::stoi(
				(savedata[8].find(":")==std::string::npos)? savedata[8]:savedata[8].replace(savedata[8].find(":"),1,""))) {
					switch(ui.schedule_check_2->checkState()) {
						case Qt::PartiallyChecked: if (!statusl) emit lockSignal(); break;
						case Qt::Checked: if (statusl) emit unlockSignal(); break;
					}
				}
			if (ui.schedule_check_3->checkState()!=Qt::Unchecked) if (c_time == std::stoi(
				(savedata[9].find(":")==std::string::npos)? savedata[9]:savedata[9].replace(savedata[9].find(":"),1,""))) {
					switch(ui.schedule_check_3->checkState()) {
						case Qt::PartiallyChecked: if (!statusl) emit lockSignal(); break;
						case Qt::Checked: if (statusl) emit unlockSignal(); break;
					}
				}
			if (ui.schedule_check_4->checkState()!=Qt::Unchecked) if (c_time == std::stoi(
				(savedata[10].find(":")==std::string::npos)? savedata[10]:savedata[10].replace(savedata[10].find(":"),1,""))) {
					switch(ui.schedule_check_4->checkState()) {
						case Qt::PartiallyChecked: if (!statusl) emit lockSignal(); break;
						case Qt::Checked: if (statusl) emit unlockSignal(); break;
					}
				}
			if (ui.schedule_check_5->checkState()!=Qt::Unchecked) if (c_time == std::stoi(
				(savedata[11].find(":")==std::string::npos)? savedata[11]:savedata[11].replace(savedata[11].find(":"),1,""))) {
					switch(ui.schedule_check_5->checkState()) {
						case Qt::PartiallyChecked: if (!statusl) emit lockSignal(); break;
						case Qt::Checked: if (statusl) emit unlockSignal(); break;
					}
				}
			if (ui.schedule_check_6->checkState()!=Qt::Unchecked) if (c_time == std::stoi(
				(savedata[12].find(":")==std::string::npos)? savedata[12]:savedata[12].replace(savedata[12].find(":"),1,""))) {
					switch(ui.schedule_check_6->checkState()) {
						case Qt::PartiallyChecked: if (!statusl) emit lockSignal(); break;
						case Qt::Checked: if (statusl) emit unlockSignal(); break;
					}
				}
			  // std::cout << "c_time: " << c_time << /*" | " << savedata[7]/*.replace(savedata[7].find(":"),1,"") << */"\n";
			std::this_thread::sleep_for(std::chrono::minutes(1));
		}
	}
};

Schedule schedule;

Qt::CheckState stringToCheckState(std::string str) {
    if (str=="0") return Qt::Unchecked;
	else if (str=="1") return Qt::PartiallyChecked;
	else if (str=="2") return Qt::Checked;
	else return Qt::Unchecked;
}

int checkStateToInt(Qt::CheckState st) {
	switch(st) {
		case Qt::Unchecked: return 0;
		case Qt::PartiallyChecked: return 1;
		case Qt::Checked: return 2;
	}
	return 3;
}

void load() {
	if (!std::filesystem::exists(appdataP + "/save.bin")) {
		savedata = {
			/*pass*/					"pass",
			/*schedule_check_[1~6]*/	"0","0","0","0","0","0",
			/*schedule_time_[1~6]*/		"00:00","00:00","00:00","00:00","00:00","00:00",
			/*shortcut_enable_[1,2]*/	"false","false",
			/*shortcut_black_[1,2]*/	"false","false",
			/*shortcut_modifier_[1,2]*/	"0","0",
			/*shortcut_key_[1,2]*/		"0","0",
			/*screensaver_darkness*/	"0",
			/*screensaver_type*/		"0",
			/*other_[1,2]*/				"false","false"
		};
		return;
	}
	
	std::ifstream savefile(appdataP + "/save.bin",std::ios_base::binary);
	std::string token;
	QTime time_s;
	while (std::getline(savefile, token, ',')) savedata.emplace_back(token);
	/* std::cout << "LoadData\n";
	for (std::string i: savedata) std::cout << i << "\n"; */

	password=savedata[0];
	ui.schedule_check_1->setCheckState(stringToCheckState(savedata[1]));
	ui.schedule_check_2->setCheckState(stringToCheckState(savedata[2]));
	ui.schedule_check_3->setCheckState(stringToCheckState(savedata[3]));
	ui.schedule_check_4->setCheckState(stringToCheckState(savedata[4]));
	ui.schedule_check_5->setCheckState(stringToCheckState(savedata[5]));
	ui.schedule_check_6->setCheckState(stringToCheckState(savedata[6]));
	ui.schedule_time_1->setTime(QTime::fromString(QString::fromStdString(savedata[7]), "hh:mm"));
	ui.schedule_time_2->setTime(QTime::fromString(QString::fromStdString(savedata[8]), "hh:mm"));
	ui.schedule_time_3->setTime(QTime::fromString(QString::fromStdString(savedata[9]), "hh:mm"));
	ui.schedule_time_4->setTime(QTime::fromString(QString::fromStdString(savedata[10]), "hh:mm"));
	ui.schedule_time_5->setTime(QTime::fromString(QString::fromStdString(savedata[11]), "hh:mm"));
	ui.schedule_time_6->setTime(QTime::fromString(QString::fromStdString(savedata[12]), "hh:mm"));
	ui.shortcut_enable_1->setChecked(string_to_bool(savedata[13]));
	ui.shortcut_enable_2->setChecked(string_to_bool(savedata[14]));
	ui.shortcut_black_1->setChecked(string_to_bool(savedata[15]));
	ui.shortcut_black_2->setChecked(string_to_bool(savedata[16]));
	ui.shortcut_modifier_1->setCurrentIndex(std::stoi(savedata[17]));
	ui.shortcut_modifier_2->setCurrentIndex(std::stoi(savedata[18]));
	ui.shortcut_key_1->setCurrentIndex(std::stoi(savedata[19]));
	ui.shortcut_key_2->setCurrentIndex(std::stoi(savedata[20]));
	ui.screensaver_darkness->setValue(std::stoi(savedata[21]));
	ui.screensaver_type->setCurrentIndex(std::stoi(savedata[22]));
	ui.other_1->setChecked(string_to_bool(savedata[23]));
	ui.other_2->setChecked(string_to_bool(savedata[24]));
}

void save() {
	std::ofstream savefile(appdataP + "/save.bin",std::ios_base::binary);
	savedata.clear();
	savedata.emplace_back(password);
	savedata.emplace_back(std::to_string(checkStateToInt(ui.schedule_check_1->checkState())));
	savedata.emplace_back(std::to_string(checkStateToInt(ui.schedule_check_2->checkState())));
	savedata.emplace_back(std::to_string(checkStateToInt(ui.schedule_check_3->checkState())));
	savedata.emplace_back(std::to_string(checkStateToInt(ui.schedule_check_4->checkState())));
	savedata.emplace_back(std::to_string(checkStateToInt(ui.schedule_check_5->checkState())));
	savedata.emplace_back(std::to_string(checkStateToInt(ui.schedule_check_6->checkState())));
	savedata.emplace_back(ui.schedule_time_1->time().toString("hh:mm").toStdString());
	savedata.emplace_back(ui.schedule_time_2->time().toString("hh:mm").toStdString());
	savedata.emplace_back(ui.schedule_time_3->time().toString("hh:mm").toStdString());
	savedata.emplace_back(ui.schedule_time_4->time().toString("hh:mm").toStdString());
	savedata.emplace_back(ui.schedule_time_5->time().toString("hh:mm").toStdString());
	savedata.emplace_back(ui.schedule_time_6->time().toString("hh:mm").toStdString());
	savedata.emplace_back(ui.shortcut_enable_1->isChecked()?"true":"false");
	savedata.emplace_back(ui.shortcut_enable_2->isChecked()?"true":"false");
	savedata.emplace_back(ui.shortcut_black_1->isChecked()?"true":"false");
	savedata.emplace_back(ui.shortcut_black_2->isChecked()?"true":"false");
	savedata.emplace_back(std::to_string(ui.shortcut_modifier_1->currentIndex()));
	savedata.emplace_back(std::to_string(ui.shortcut_modifier_2->currentIndex()));
	savedata.emplace_back(std::to_string(ui.shortcut_key_1->currentIndex()));
	savedata.emplace_back(std::to_string(ui.shortcut_key_2->currentIndex()));
	savedata.emplace_back(std::to_string(ui.screensaver_darkness->value()));
	savedata.emplace_back(std::to_string(ui.screensaver_type->currentIndex()));
	savedata.emplace_back(ui.other_1->isChecked()?"true":"false");
	savedata.emplace_back(ui.other_2->isChecked()?"true":"false");
	std::string outString;
	for (std::string i: savedata) outString+= i + ",";
		// std::cout << outString << "\n";
	savefile << outString;
}

void autostart(std::string argv0) {
	std::string path = "C:/Users/" + std::string(std::getenv("username")) + "/AppData/Roaming/Microsoft/Windows/Start Menu/Programs/Startup/lockStarter.bat";
	if (ui.other_2->isChecked() && !std::filesystem::exists(path)) {
		std::ofstream ofs(path,std::ios_base::binary);
		ofs << "@echo off\ncd " << std::filesystem::absolute(argv0).parent_path() << "\nstart " << argv0;
	} else std::filesystem::remove(path);
}

LRESULT CALLBACK KeyboardProc(int nCode, WPARAM wParam, LPARAM lParam) {
    if (nCode == HC_ACTION) {
        PKBDLLHOOKSTRUCT p = (PKBDLLHOOKSTRUCT)lParam;
        if (wParam == WM_KEYDOWN || wParam == WM_SYSKEYDOWN) {
            if (p->vkCode == VK_MENU || p->vkCode == VK_TAB || p->vkCode == VK_LWIN || p->vkCode == VK_RWIN || p->vkCode == VK_CONTROL
                || (p->vkCode == VK_ESCAPE && GetAsyncKeyState(VK_CONTROL) < 0) ) return 1;
        }
    }
    return CallNextHookEx(keyboardHook, nCode, wParam, lParam);
}





int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
	MainWindow* window = new MainWindow(&statusl);
    ui.setupUi(window);
    a.setStyle(QStyleFactory::create("Fusion"));
    window->showFullScreen();

	load();
/*	std::cout << "StartLoadData\n";
	for (std::string i: savedata) std::cout << i << "\n";*/

	if (!std::filesystem::exists(appdataP)) {
		std::filesystem::create_directories(appdataP);
		std::ofstream statusF(appdataP + "/status.dat",std::ios_base::binary);
		statusF << false;
	}
	std::ifstream statusF(appdataP + "/status.dat",std::ios_base::binary);
	std::string statusFIs;
	std::getline(statusF, statusFIs);
	if (std::stoi(statusFIs) && ui.other_1->isChecked()) lock(); else unlock();
	
    hwnd = reinterpret_cast<HWND>(window->winId());

	QObject::connect(ui.lineEdit1, &QLineEdit::returnPressed, [&] {
        if (ui.lineEdit1->text().toStdString()==password) if (statusl) unlock(); else ui.lineEdit2->setEnabled(true);});
    QObject::connect(ui.lineEdit2, &QLineEdit::returnPressed, [&] {
        if (statusl) {
			if (ui.lineEdit2->text().toStdString()=="taskkill /im lock.exe /f") exit(0);
		} else {
				password=ui.lineEdit2->text().toStdString();
				ui.lineEdit2->setText("");
				ui.lineEdit2->setEnabled(false);
				save();
			}});
    QObject::connect(ui.pushButton, &QPushButton::clicked, [&] {if (statusl) {statusl=false;unlock();} else {statusl=true;lock();}});
    QObject::connect(ui.pushButton2, &QPushButton::clicked, [&] {window->showMinimized();});
	
	// 自動保存 connect
	QObject::connect(ui.schedule_check_1, &QCheckBox::stateChanged, [&] {save();});
	QObject::connect(ui.schedule_check_2, &QCheckBox::stateChanged, [&] {save();});
	QObject::connect(ui.schedule_check_3, &QCheckBox::stateChanged, [&] {save();});
	QObject::connect(ui.schedule_check_4, &QCheckBox::stateChanged, [&] {save();});
	QObject::connect(ui.schedule_check_5, &QCheckBox::stateChanged, [&] {save();});
	QObject::connect(ui.schedule_check_6, &QCheckBox::stateChanged, [&] {save();});
	QObject::connect(ui.schedule_time_1, &QTimeEdit::timeChanged, [&] {save();});
	QObject::connect(ui.schedule_time_2, &QTimeEdit::timeChanged, [&] {save();});
	QObject::connect(ui.schedule_time_3, &QTimeEdit::timeChanged, [&] {save();});
	QObject::connect(ui.schedule_time_4, &QTimeEdit::timeChanged, [&] {save();});
	QObject::connect(ui.schedule_time_5, &QTimeEdit::timeChanged, [&] {save();});
	QObject::connect(ui.schedule_time_6, &QTimeEdit::timeChanged, [&] {save();});
	QObject::connect(ui.shortcut_enable_1, &QCheckBox::stateChanged, [&] {setHotkey();save();});
	QObject::connect(ui.shortcut_enable_2, &QCheckBox::stateChanged, [&] {setHotkey();save();});
	QObject::connect(ui.shortcut_black_1, &QCheckBox::stateChanged, [&] {save();});
	QObject::connect(ui.shortcut_black_2, &QCheckBox::stateChanged, [&] {save();});
	QObject::connect(ui.shortcut_modifier_1, &QComboBox::currentIndexChanged, [&] {setHotkey();save();});
	QObject::connect(ui.shortcut_modifier_2, &QComboBox::currentIndexChanged, [&] {setHotkey();save();});
	QObject::connect(ui.shortcut_key_1, &QComboBox::currentIndexChanged, [&] {setHotkey();save();});
	QObject::connect(ui.shortcut_key_2, &QComboBox::currentIndexChanged, [&] {setHotkey();save();});
	QObject::connect(ui.screensaver_darkness, &QAbstractSlider::valueChanged, [&] {save();});
	QObject::connect(ui.screensaver_type, &QComboBox::currentIndexChanged, [&] {save();});
	QObject::connect(ui.other_1, &QCheckBox::stateChanged, [&] {save();});
	QObject::connect(ui.other_2, &QCheckBox::stateChanged, [&] {save();});
	


	// 起動時 schedule_time 有効状態反映
	if (ui.schedule_check_1->checkState()==Qt::Unchecked) ui.schedule_time_1->setEnabled(false);
	if (ui.schedule_check_2->checkState()==Qt::Unchecked) ui.schedule_time_2->setEnabled(false);
	if (ui.schedule_check_3->checkState()==Qt::Unchecked) ui.schedule_time_3->setEnabled(false);
	if (ui.schedule_check_4->checkState()==Qt::Unchecked) ui.schedule_time_4->setEnabled(false);
	if (ui.schedule_check_5->checkState()==Qt::Unchecked) ui.schedule_time_5->setEnabled(false);
	if (ui.schedule_check_6->checkState()==Qt::Unchecked) ui.schedule_time_6->setEnabled(false);
	QObject::connect(ui.schedule_check_1, &QCheckBox::clicked, [&](int s) {
		save(); if (s==0) ui.schedule_time_1->setEnabled(false); else ui.schedule_time_1->setEnabled(true);});
	QObject::connect(ui.schedule_check_2, &QCheckBox::clicked, [&](int s) {
		save(); if (s==0) ui.schedule_time_2->setEnabled(false); else ui.schedule_time_2->setEnabled(true);});
	QObject::connect(ui.schedule_check_3, &QCheckBox::clicked, [&](int s) {
		save(); if (s==0) ui.schedule_time_3->setEnabled(false); else ui.schedule_time_3->setEnabled(true);});
	QObject::connect(ui.schedule_check_4, &QCheckBox::clicked, [&](int s) {
		save(); if (s==0) ui.schedule_time_4->setEnabled(false); else ui.schedule_time_4->setEnabled(true);});
	QObject::connect(ui.schedule_check_5, &QCheckBox::clicked, [&](int s) {
		save(); if (s==0) ui.schedule_time_5->setEnabled(false); else ui.schedule_time_5->setEnabled(true);});
	QObject::connect(ui.schedule_check_6, &QCheckBox::clicked, [&](int s) {
		save(); if (s==0) ui.schedule_time_6->setEnabled(false); else ui.schedule_time_6->setEnabled(true);});
	
	setHotkey();
	
	
	schedule.start();
	QObject::connect(&schedule, &Schedule::lockSignal, &schedule, &Schedule::lockSlot);
	QObject::connect(&schedule, &Schedule::unlockSignal, &schedule, &Schedule::unlockSlot);
	// QObject::connect(&signalSlot, &SignalSlot::screenSaverSignal, &signalSlot, &SignalSlot::screenSaverSlot);



	QObject::connect(ui.other_2, &QCheckBox::stateChanged, [=] {autostart(argv[0]);});

	// blackWindow screenSaver 一旦無効化
	ui.shortcut_black_1->setEnabled(false);
	ui.shortcut_black_2->setEnabled(false);
	ui.screensaver_box->setEnabled(false);



// TestArea

/*	QWidget blackWidget;
	window->setCentralWidget(&blackWidget);*/

// ...



	MSG msg;
    while (GetMessage(&msg, nullptr, 0, 0)) {
        if (msg.message == WM_HOTKEY && msg.wParam == 98101) lockHotkey(1);
        if (msg.message == WM_HOTKEY && msg.wParam == 98102) lockHotkey(2);
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
	
    return a.exec();
}

#include "lock.moc"