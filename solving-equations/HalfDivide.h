#ifndef SOLVING_EQUATIONS_HALFDIVIDE_H
#define SOLVING_EQUATIONS_HALFDIVIDE_H

#include "equations.h"
#include <iostream>

using std::cin;

class HalfDivide : all {
public:
    void main();

private:
    //判断输入的a和b的结果是否为一正一负
    bool equation_judgment(const long double a, const long double b);
};

#endif //SOLVING_EQUATIONS_HALFDIVIDE_H
