#include "HalfDivide.h"
#include <iostream>

using namespace std;

HalfDivide::HalfDivide(equations equations, solving_equations_data data) {
    //输入二分法的最开始的两个数
    long double a, b;
    while (true) {
        cout << "请输入运算范围a b：";
        cin >> a;
        cin >> b;
        if (equation_judgment(equations, a, b)) {
            break;
        } else {
            cout << "ERROR:a b取值错误，请重新输入" << endl;
        }
    }
    //二分法主程序
    while (true) {
        equations.answer = (a + b) / 2;
        if (get_fx(equations, a) == 0) {
            //左值为结果
            equations.answer = a;
            putOutAnswer(equations, data);
            break;
        } else if (get_fx(equations, b) == 0) {
            //右值为结果
            equations.answer = b;
            putOutAnswer(equations, data);
            break;
        } else if (get_fx(equations, equations.answer) == 0) {
            //二分法分到结果
            putOutAnswer(equations, data);
            break;
        } else if (equation_judgment(equations, a, equations.answer)) {
            //二分法中值取代右值
            b = equations.answer;
        } else if (equation_judgment(equations, equations.answer, b)) {
            //二分法中值取代左值
            a = equations.answer;
        }
        timeLimit(data);
    }
}

bool HalfDivide::equation_judgment(const equations &equations, long double a, long double b) {
    const long double answer_a = get_fx(equations, a);
    const long double answer_b = get_fx(equations, b);
    if (((answer_a <= 0) && (answer_b >= 0)) || (answer_a >= 0) && (answer_b <= 0)) {
        return true;
    } else {
        return false;
    }
}