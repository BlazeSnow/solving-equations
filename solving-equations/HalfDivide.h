#ifndef SOLVING_EQUATIONS_HALFDIVIDE_H
#define SOLVING_EQUATIONS_HALFDIVIDE_H

#include "main.h"

class HalfDivide : public solving_equations {
public:
    HalfDivide(equations equations, solving_equations_data data);

private:
    //判断输入的a和b的结果是否为一正一负
    bool equation_judgment(const equations &equations, long double a, long double b);
};

#endif //SOLVING_EQUATIONS_HALFDIVIDE_H
