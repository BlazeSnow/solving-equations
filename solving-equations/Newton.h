#ifndef SOLVING_EQUATIONS_NEWTON_H
#define SOLVING_EQUATIONS_NEWTON_H

#include "solving-equations.h"
#include <iostream>
#include <cmath>

using std::cin;

//牛顿迭代法
class Newton : all {
public:
    void main();

private:
    //计算导数的答案
    long double get_derivation(long double x) ;

    //计算牛顿迭代的结果
    long double equation_newton(long double x);
};

#endif //SOLVING_EQUATIONS_NEWTON_H
