#include <iostream>
#include <fstream>
#include <filesystem>
#include <valarray>
#include "solving-equations.h"

using namespace std;

int main() {
    fstream file("solving-equations.txt", ios::in);
    if (file.is_open()) {
        //如果有文件
        file.close();
        int choose;
        cout << "您需要解方程(0)、求微分(1)还是求积分(2)：" << endl;
        cin >> choose;
        if (choose == 0) {
            solving_equations();
        } else {
            cout << "ERROR:输入不合法，请重新开始程序" << endl;
            return -1;
        }
    } else {
        //如果没有文件
        fstream file1("solving-equations.txt", ios::out);
        if (file1.is_open()) {
            file1.close();
            cout << "已创建新文件\"solving-equations.txt\"。" << endl;
            //打印文件路径
            cout << "文件路径:" << std::filesystem::current_path() << endl;
        } else {
            //创建文件失败
            cout << "ERROR:创建文件失败" << endl;
            return -1;
        }
    }
    return 0;
}