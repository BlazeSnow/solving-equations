#include "HalfDivide.h"
#include <iostream>

using namespace std;

HalfDivide::HalfDivide() {
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

bool HalfDivide::equation_judgment(const long double a, const long double b) {
    long double answer_a = get_fx(a);
    long double answer_b = get_fx(b);
    if (((answer_a <= 0) && (answer_b >= 0)) || (answer_a >= 0) && (answer_b <= 0)) {
        return true;
    } else {
        return false;
    }
}