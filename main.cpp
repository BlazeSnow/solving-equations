#include <iostream>
#include <fstream>
#include <filesystem>
#include <valarray>
#include "main.h"
#include "solving-equations/HalfDivide.h"
#include "solving-equations/Newton.h"
#include "solving-equations/Secant_method.h"

using namespace std;

int main() {
    fstream file("sloving-equations.txt", ios::in);
    if (file.is_open()) {
        //如果有文件
        file.close();
        int choose;
        cout << "您需要解方程(0)、求微分(1)还是求积分(2)：" << endl;
        cin >> choose;
        if (choose == 0) {
            solving_equations a;
        } else {
            cout << "ERROR:输入不合法，请重新开始程序" << endl;
            return -1;
        }
    } else {
        //如果没有文件
        fstream file1("sloving-equations.txt", ios::out);
        if (file1.is_open()) {
            file1.close();
            cout << "已创建新文件\"sloving-equations.txt\"。" << endl;
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

solving_equations::solving_equations() {
    input();
    //判断使用哪种方法
    int panduan;
    cout << "使用二分法(0)，牛顿迭代法(1)，弦截法(2)：" << endl;
    cin >> panduan;
    if (panduan == 0) {
        HalfDivide a;
    } else if (panduan == 1) {
        Newton a;
    } else if (panduan == 2) {
        Secant_method a;
    } else {
        cout << "ERROR:输入内容不合法，请重新开始程序" << endl;
        abort();
    }
}

//输入文件中的数据到数组
void solving_equations::input() {
    fstream file("sloving-equations.txt", ios::in);
    if (file.is_open()) {
        //读取文件
        solving temp;
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
        cout << "文件路径：" << std::filesystem::current_path() << endl;
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

void solving_equations::putOutAnswer() const {
    cout << "answer = " << answer << endl;
    cout << "迭代次数" << times << "次" << endl;
}

void solving_equations::timeLimit() {
    times++;
    if (times > time_limit) {
        cout << "迭代次数超过" << 10000000 << "次" << endl;
        cout << "已终止程序" << endl;
        abort();
    }
}

long double solving_equations::get_fx(long double x) {
    long double y = 0;
    for (auto &i: equ) {
        y += i.coefficient * (pow(x, i.power));
    }
    return y;
}