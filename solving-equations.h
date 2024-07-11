#ifndef SOLVING_EQUATIONS_SOLVING_EQUATIONS_H
#define SOLVING_EQUATIONS_SOLVING_EQUATIONS_H

#include <iostream>
#include <fstream>
#include <filesystem>
#include <vector>
#include <cmath>

using std::cout;
using std::endl;
using std::cin;
using std::vector;
using std::fstream;
using std::ios;
using std::setprecision;

//迭代次数限制
#define time_limit 100000

//方程式
struct equations;

//总方程读取
class all {
public:
    void input();

    void putOutAnswer() const;

    void timeLimit();

    long double get_fx(long double x);
};

//二分法
class HalfDivide : public all {
public:
    void main() {};
};

//牛顿迭代法
class Newton : public all {
public:
    void main() {};
};

//弦截法
class Secant_method : public all {
public:
    void main() {};
};

#endif //SOLVING_EQUATIONS_SOLVING_EQUATIONS_H
