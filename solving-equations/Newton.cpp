#include "Newton.h"

void Newton::main() {
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

long double Newton::get_derivation(long double x) {
    long double y = 0;
    for (auto &i: equ) {
        y += (i.coefficient * i.power) * (pow(x, i.power - 1));
    }
    return y;
}

long double Newton::equation_newton(long double x) {
    long double answer = x - (get_fx(x) / get_derivation(x));
    return answer;
}