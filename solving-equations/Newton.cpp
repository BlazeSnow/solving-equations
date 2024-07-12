#include "Newton.h"
#include <iostream>
#include <cmath>

using namespace std;

Newton::Newton(equations equations, solving_equations_data data) {
    //开始运算
    cout << "请输入初值：";
    cin >> equations.answer;
    while (true) {
        if (equation_newton(equations, equations.answer) == equations.answer) {
            putOutAnswer(equations, data);
            break;
        }
        equations.answer = equation_newton(equations, equations.answer);
        timeLimit(data);
    }
}

long double Newton::get_derivation(const equations &equations, long double x) {
    long double y = 0;
    for (auto &i: equations.equ) {
        y += (i.coefficient * i.power) * (pow(x, i.power - 1));
    }
    return y;
}

long double Newton::equation_newton(const equations &equations, long double x) {
    return x - (get_fx(equations, x) / get_derivation(equations, x));
}