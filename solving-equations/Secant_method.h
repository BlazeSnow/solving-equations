#ifndef SOLVING_EQUATIONS_SECANT_METHOD_H
#define SOLVING_EQUATIONS_SECANT_METHOD_H

#include "solving-equations.h"
#include <iostream>

using std::cin;

//弦截法
class Secant_method : solving_equations {
public:
    void main();

private:
    long double x0 = 0;
    long double x1 = 0;

    //弦截法
    long double get_Secant(long double num0, long double num1);
};

#endif //SOLVING_EQUATIONS_SECANT_METHOD_H
