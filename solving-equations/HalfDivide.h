#ifndef SOLVING_EQUATIONS_HALFDIVIDE_H
#define SOLVING_EQUATIONS_HALFDIVIDE_H

#include "solving-equations.h"
#include <iostream>

using std::cin;

class HalfDivide : solving_equations {
public:
    void main();

private:
    //判断输入的a和b的结果是否为一正一负
    bool equation_judgment(long double a, long double b);
};

#endif //SOLVING_EQUATIONS_HALFDIVIDE_H
