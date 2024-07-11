#include "equations.h"

#include <fstream>
#include <filesystem>
#include <iostream>
#include <cmath>

using namespace std;

void all::input() {
    fstream file("sloving-equations.txt", ios::in);
    if (file.is_open()) {
        //读取文件
        equations temp{};
        for (int i = 0;; i++) {
            file >> temp.coefficient;
            file >> temp.power;
            equ.push_back(temp);
            if (file.eof()) {
                break;
            }
        }
        file.close();
        //输出路径
        cout << "读取文件成功" << endl;
        std::filesystem::path path = std::filesystem::current_path();
        cout << "文件路径：" << path << endl;
        //输出原方程
        cout << "方程：f(x) = ";
        for (auto &i: equ) {
            cout << setiosflags(ios::showpos);
            cout << i.coefficient;
            cout << resetiosflags(ios::showpos);
            cout << " x ";
            cout << i.power << " ";
        }
        cout << endl;
        //输入精度
        cout << "输入精度（保留几位小数）：";
        cin >> precisionNumber;
        long double precision = pow(10, -precisionNumber);
        cout << setprecision(precisionNumber);
        cout << "精度为" << precision << endl;
    }
}

void all::putOutAnswer() const {
    cout << "answer = " << answer << endl;
    cout << "迭代次数" << times << "次" << endl;
}

void all::timeLimit() {
    times++;
    if (times > time_limit) {
        cout << "迭代次数超过" << 10000000 << "次" << endl;
        cout << "已终止程序" << endl;
        abort();
    }
}

long double all::get_fx(long double x) {
    long double y = 0;
    for (auto &i: equ) {
        y += i.coefficient * (pow(x, i.power));
    }
    return y;
}