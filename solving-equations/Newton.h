#ifndef SOLVING_EQUATIONS_NEWTON_H
#define SOLVING_EQUATIONS_NEWTON_H

#include "main.h"

//牛顿迭代法
class Newton : public solving_equations {
public:
    Newton(equations equations, solving_equations_data data);

private:
    //计算导数的答案
    static long double get_derivation(const equations &equations, long double x);

    //计算牛顿迭代的结果
    static long double equation_newton(const equations &equations, long double x);
};

#endif //SOLVING_EQUATIONS_NEWTON_H
