//Copyright (C) 2024 BlazeSnow
//保留所有权利
//本程序以GNU General Public License v3.0的条款发布
#include <iostream>
#include <fstream>
#include <filesystem>
#include "Redistributable/solving-equations.h"

using namespace std;

int main() {
    cout << "Copyright (C) 2024 BlazeSnow.保留所有权利。" << endl;
    cout << "本程序以GNU General Public License v3.0的条款发布。" << endl << endl;
    cout << "https://github.com/BlazeSnow/solving-equations" << endl << endl;
    fstream file("solving-equations.txt", ios::in);
    if (file.is_open()) {
        //如果有文件
        file.close();
        int choose;
        cout << "解方程(1)" << endl;
        cout << "插值(2)" << endl;
        cout << "求逼近函数(3)" << endl;
        cout << "求数值积分(4)" << endl;
        cout << "求数值微分(5)" << endl;
        cout << "输入：";
        cin >> choose;
        cout << endl;
        if (choose == 1) {
            solving_equations();
        } else if (choose == 2 || choose == 3 || choose == 4 || choose == 5) {
            cout << "正在开发中……" << endl;
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