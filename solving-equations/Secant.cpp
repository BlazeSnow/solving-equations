#include "Secant.h"
#include <iostream>

using namespace std;

Secant::Secant(equations equations, solving_equations_data data) {
    long double x0 = 0;
    long double x1 = 0;
    cout << "请输入x0和x1：" << endl;
    cin >> x0 >> x1;
    while (true) {
        long double temp;
        temp = get_Secant(equations, x0, x1);
        x0 = x1;
        x1 = temp;
        if (x0 == x1) {
            equations.answer = x1;
            putOutAnswer(equations, data);
            break;
        } else {
            timeLimit(data);
        }
    }
}

long double Secant::get_Secant(const equations &equations, long double num0, long double num1) {
    return num1 - (get_fx(equations, num1) * ((num1 - num0) / (get_fx(equations, num1) - get_fx(equations, num0))));
}