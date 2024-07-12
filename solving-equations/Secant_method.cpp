#include "Secant_method.h"
#include <iostream>

using namespace std;

Secant_method::Secant_method() {
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

long double Secant_method::get_Secant(long double num0, long double num1) {
    return num1 - get_fx(num1) * (num1 - num0) / (get_fx(num1) - get_fx(num0));
}