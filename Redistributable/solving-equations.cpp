#include <cmath>
#include <iostream>
#include <fstream>
#include <filesystem>
#include "all.h"

using namespace std;

//弦截法
class Secant : solving_equations {
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
        return num1 - get_fx(num1) * (num1 - num0) / (get_fx(num1) - get_fx(num0));
    }
};

//牛顿迭代法
class Newton : solving_equations {
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
        return x - (get_fx(x) / get_derivation(x));
    }
};

//二分法
class HalfDivide : solving_equations {
public:
    void main() {
        input();
        //输入二分法的最开始的两个数
        long double a, b;
        while (true) {
            cout << "请输入运算范围a b：";
            cin >> a;
            cin >> b;
            if (equation_judgment(a, b)) {
                break;
            } else {
                cout << "ERROR:a b取值错误，请重新输入" << endl;
            }
        }
        //二分法主程序
        while (true) {
            answer = (a + b) / 2;
            if (get_fx(a) == 0.0) {
                //左值为结果
                answer = a;
                putOutAnswer();
                break;
            } else if (get_fx(b) == 0.0) {
                //右值为结果
                answer = b;
                putOutAnswer();
                break;
            } else if (get_fx(answer) == 0.0) {
                //二分法分到结果
                putOutAnswer();
                break;
            } else if (equation_judgment(a, answer)) {
                //二分法中值取代右值
                b = answer;
            } else if (equation_judgment(answer, b)) {
                //二分法中值取代左值
                a = answer;
            }
            timeLimit();
        }
    }

private:
    //判断输入的a和b的结果是否为一正一负
    bool equation_judgment(const long double a, const long double b) {
        long double answer_a = get_fx(a);
        long double answer_b = get_fx(b);
        if (((answer_a <= 0) && (answer_b >= 0)) || (answer_a >= 0) && (answer_b <= 0)) {
            return true;
        } else {
            return false;
        }
    }
};

int solving_equations() {
    fstream file("solving-equations.txt", ios::in);
    if (file.is_open()) {
        //如果有文件
        file.close();
        //判断使用哪种方法
        int panduan = -1;
        cout << "使用二分法(0)，牛顿迭代法(1)，弦截法(2)：" << endl;
        cin >> panduan;
        if (panduan == 0) {
            HalfDivide a;
            a.main();
        } else if (panduan == 1) {
            Newton a;
            a.main();
        } else if (panduan == 2) {
            Secant a;
            a.main();
        } else {
            cout << "ERROR:输入内容不合法，请重新开始程序" << endl;
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