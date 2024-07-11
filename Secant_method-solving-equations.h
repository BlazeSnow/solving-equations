#ifndef SOLVING_EQUATIONS_SECANT_METHOD_SOLVING_EQUATIONS_H
#define SOLVING_EQUATIONS_SECANT_METHOD_SOLVING_EQUATIONS_H

#include "equations.h"

class Secant_method : public all {
public:
    void main(){};

private:
    long double x0 = 0;
    long double x1 = 0;

    //弦截法
    long double get_Secant(long double num0, long double num1);
};

#endif //SOLVING_EQUATIONS_SECANT_METHOD_SOLVING_EQUATIONS_H
