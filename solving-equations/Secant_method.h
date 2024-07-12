#ifndef SOLVING_EQUATIONS_SECANT_METHOD_H
#define SOLVING_EQUATIONS_SECANT_METHOD_H

#include "main.h"

//弦截法
class Secant_method : public solving_equations {
public:
    Secant_method();

private:
    long double x0 = 0;
    long double x1 = 0;

    //弦截法
    long double get_Secant(long double num0, long double num1);
};

#endif //SOLVING_EQUATIONS_SECANT_METHOD_H
