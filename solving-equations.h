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
struct equations {
    //系数
    long double coefficient = 0;
    //幂
    long double power = 0;
};

//总方程读取
class all {
public:
    //方程式数组
    vector<equations> equ{};
    //答案
    long double answer = 0;
    //迭代次数
    int times = 0;
    //保留小数位数
    int precisionNumber = 1;

    //输入文件中的数据到数组
    void input();

    //输出答案和迭代次数
    void putOutAnswer() const;

    //迭代次数++以及判断是否超出限制
    void timeLimit();

    //计算函数的答案
    long double get_fx(long double x);
};

//二分法
class HalfDivide : public all {
public:
    void main();

private:
    //判断输入的a和b的结果是否为一正一负
    bool equation_judgment(long double a, long double b);
};

//牛顿迭代法
class Newton : public all {
public:
    void main();

private:
    //计算导数的答案
    long double get_derivation(long double x);

    //计算牛顿迭代的结果
    long double equation_newton(long double x);
};

//弦截法
class Secant_method : public all {
public:
    void main();

private:
    long double x0 = 0;
    long double x1 = 0;

    //弦截法
    long double get_Secant(long double num0, long double num1);
};

#endif //SOLVING_EQUATIONS_SOLVING_EQUATIONS_H
