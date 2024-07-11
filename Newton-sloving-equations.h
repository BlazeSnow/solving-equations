#ifndef SOLVING_EQUATIONS_NEWTON_SLOVING_EQUATIONS_H
#define SOLVING_EQUATIONS_NEWTON_SLOVING_EQUATIONS_H

#include "equations.h"

class Newton : public all {
public:
    void main();

private:
    //计算导数的答案
    long double get_derivation(long double x);

    //计算牛顿迭代的结果
    long double equation_newton(long double x);
};

#endif //SOLVING_EQUATIONS_NEWTON_SLOVING_EQUATIONS_H
