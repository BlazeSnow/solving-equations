#include <iostream>
#include <fstream>
#include <filesystem>
#include <vector>
#include <cmath>

using std::cout;
using std::endl;
using std::cin;
using std::vector;
using std::fstream;
using std::ios;
using std::setprecision;

#include "equations.h"

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