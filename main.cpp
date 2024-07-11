#include <cmath>
#include <iomanip>
#include <iostream>
#include <vector>
#include <fstream>
#include <filesystem>
#include "equations.h"
#include "HalfDivide-solving-equations.h"

using namespace std;

class all;

//弦截法
class Secant_method : all {
public:
    void main() {
        input();
        cout << "请输入x0和x1：" << endl;
        cin >> x0 >> x1;
        while (true) {
            long double temp;
            temp = get_Secant(x0, x1);
            x0 = x1;
            x1 = temp;
            if (x0 == x1) {
                answer = x1;
                putOutAnswer();
                break;
            } else {
                timeLimit();
            }
        }
    }

private:
    long double x0 = 0;
    long double x1 = 0;

    //弦截法
    long double get_Secant(long double num0, long double num1) {
        long double answer;
        answer = num1 - get_fx(num1) * (num1 - num0) / (get_fx(num1) - get_fx(num0));
        return answer;
    }
};

//牛顿迭代法
class Newton : all {
public:
    void main() {
        input();
        //开始运算
        cout << "请输入初值：";
        cin >> answer;
        while (true) {
            if (equation_newton(answer) == answer) {
                putOutAnswer();
                break;
            }
            answer = equation_newton(answer);
            timeLimit();
        }
    }

private:
    //计算导数的答案
    long double get_derivation(long double x) {
        long double y = 0;
        for (auto &i: equ) {
            y += (i.coefficient * i.power) * (pow(x, i.power - 1));
        }
        return y;
    }

    //计算牛顿迭代的结果
    long double equation_newton(long double x) {
        long double answer = x - (get_fx(x) / get_derivation(x));
        return answer;
    }
};

int main() {
    fstream file("BlazeSnow 解方程.txt", ios::in);
    if (file.is_open()) {
        //如果有文件
        file.close();
        //判断使用哪种方法
        int panduan = -1;
        cout << "使用二分法(0)，牛顿迭代法(1)，弦截法(2)：";
        cin >> panduan;
        if (panduan == 0) {
            HalfDivide a;
            a.main();
        } else if (panduan == 1) {
            Newton a;
            a.main();
        } else if (panduan == 2) {
            Secant_method a;
            a.main();
        } else {
            cout << "ERROR:输入内容不合法，请重新开始程序" << endl;
            return -1;
        }
    } else {
        //如果没有文件
        fstream file1("BlazeSnow 解方程.txt", ios::out);
        if (file1.is_open()) {
            file1.close();
            cout << "已创建新文件\"BlazeSnow 解方程.txt\"。" << endl;
            //打印文件路径,path变量用于存储路径
            std::filesystem::path path = std::filesystem::current_path();
            cout << "文件路径:" << path << endl;
        } else {
            //创建文件失败
            cout << "ERROR:创建文件失败" << endl;
            return -1;
        }
    }
    return 0;
}
