#include <iostream>
#include <string>
#include <windows.h>
#include <tlhelp32.h>

// プロセス名からプロセスIDを取得
DWORD GetProcessIDByName(const std::string& processName) {
    PROCESSENTRY32 entry;
    entry.dwSize = sizeof(PROCESSENTRY32);

    HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    if (Process32First(snapshot, &entry)) {
        do {
            if (processName == entry.szExeFile) {
                CloseHandle(snapshot);
                return entry.th32ProcessID;
            }
        } while (Process32Next(snapshot, &entry));
    }

    CloseHandle(snapshot);
    return 0;
}

// プロセス優先度を変更
bool SetProcessPriority(const std::string& processName, DWORD priorityClass) {
    DWORD processID = GetProcessIDByName(processName);
    if (processID == 0) {
        std::cout << "プロセスが見つかりません" << std::endl;
        return false;
    }

    HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, processID);
    if (hProcess == NULL) {
        std::cout << "プロセスを開けません" << std::endl;
        return false;
    }

    if (!SetPriorityClass(hProcess, priorityClass)) {
        std::cout << "優先度を変更できません" << std::endl;
        CloseHandle(hProcess);
        return false;
    }

    std::cout << "優先度を正常に変更しました" << std::endl;
    CloseHandle(hProcess);
    return true;
}

int main(int argc, char *argv[]) {
	if (argc != 3) {std::cout << "Usage: Task プロセス名 優先度[1:高 2:通常以上 3:通常 4:通常以下 5:低]\n"; return 0;}
    DWORD priorityClass;
    switch (std::stoi(argv[2])) {
        case 1: priorityClass = HIGH_PRIORITY_CLASS; break;
        case 2: priorityClass = ABOVE_NORMAL_PRIORITY_CLASS; break;
        case 3: priorityClass = NORMAL_PRIORITY_CLASS; break;
        case 4: priorityClass = BELOW_NORMAL_PRIORITY_CLASS; break;
        case 5: priorityClass = IDLE_PRIORITY_CLASS; break;
        default:
            std::cout << "[無効な選択です]" << std::endl;
            return 1;
    }

    // プロセスの優先度を変更
    if (!SetProcessPriority(argv[1], priorityClass)) {
        std::cout << "[エラーが発生しました]" << std::endl;
    }

    return 0;
}