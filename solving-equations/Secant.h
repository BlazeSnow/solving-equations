#ifndef SOLVING_EQUATIONS_SECANT_H
#define SOLVING_EQUATIONS_SECANT_H

#include "main.h"

//弦截法
class Secant : public solving_equations {
public:
    Secant(equations equations, solving_equations_data data);

private:
    //弦截法
    static long double get_Secant(const equations &equations, long double num0, long double num1);
};

#endif //SOLVING_EQUATIONS_SECANT_H
