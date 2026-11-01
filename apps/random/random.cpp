#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

int main() {
    // シード値を設定して乱数生成器を初期化
    std::srand(static_cast<unsigned>(time(nullptr)));

    double u_loop;
    std::cout << "文字数を入力してください: ";
    std::cin >> u_loop;

    std::string output;
    
    std::cout << "1. 数字"
			  << "2. アルファベット小文字\n"
			  << "3. アルファベット大文字\n"
			  << "4. アルファベット小文字+アルファベット大文字\n"
			  << "5. 数字+アルファベット小文字\n"
			  << "6. 数字+アルファベット大文字\n"
			  << "7. 数字+アルファベット小文字+アルファベット大文字\n";

    int type;
    std::cout << "出力タイプを選択してください: ";
    std::cin >> type;

    for (double i = 0; i < u_loop; ++i) {
        switch (type) {
            case 1:{
                output += std::to_string(std::rand() % 10);
                break;}
            case 2:{
                output += 'a' + std::rand() % 26;
                break;}
            case 3:{
                output += 'A' + std::rand() % 26;
                break;}
            case 4:{
                if (std::rand() % 2 == 0) {
                    output += 'a' + std::rand() % 26;
                } else {
                    output += 'A' + std::rand() % 26;
                }
                break;}
            case 5:{
                if (std::rand() % 2 == 0) {
                    output += std::to_string(std::rand() % 10);
                } else {
                    output += 'a' + std::rand() % 26;
                }
                break;}
            case 6:{
                if (std::rand() % 2 == 0) {
                    output += std::to_string(std::rand() % 10);
                } else {
                    output += 'A' + std::rand() % 26;
                }
                break;}
            case 7:{
                double choice = std::rand() % 3;
                if (choice == 0) {
                    output += std::to_string(std::rand() % 10);
                } else if (choice == 1) {
                    output += 'a' + std::rand() % 26;
                } else {
                    output += 'A' + std::rand() % 26;
                }
                break;}
            default:{
                std::cerr << "エラー: 不正な出力タイプ\n";
                return 1;
                }
        }
    }

    std::cout << "\n<出力>\n" << output << "\n";
}
