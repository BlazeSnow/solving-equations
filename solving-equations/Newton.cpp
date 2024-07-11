#include "all.h"
#include "Newton.h"

void Newton() {
    input();
    //开始运算
    cout << "请输入初值：";
    cin >> answer;
    while (true) {
        if (equation_newton(answer) == answer) {
            putOutAnswer();
            break;
        }
        equation_newton(answer);
        timeLimit();
    }
}

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
    long double temp = x - (get_fx(x) / get_derivation(x));
    return temp;
}
