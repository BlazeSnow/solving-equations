//Copyright (C) 2024 BlazeSnow
//保留所有权利
//本程序以GNU General Public License v3.0的条款发布
#include <iostream>
#include "Redistributable/solving-equations.h"

using namespace std;

int main() {
    cout << "Copyright (C) 2024 BlazeSnow.保留所有权利。" << endl;
    cout << "本程序以GNU General Public License v3.0的条款发布。" << endl << endl;
    cout << "https://github.com/BlazeSnow/solving-equations" << endl << endl;
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
    return 0;
}