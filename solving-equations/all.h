#ifndef SOLVING_EQUATIONS_ALL_H
#define SOLVING_EQUATIONS_ALL_H

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

//方程式
struct equations {
    //系数
    long double coefficient = 0;
    //幂
    long double power = 0;
};

//方程式数组
vector<equations> equ{};
//答案
long double answer = 0;
//迭代次数
int times = 0;
//保留小数位数
int precisionNumber = 1;

struct equations;

void input();

void putOutAnswer();

void timeLimit();

long double get_fx(long double x);

#endif //SOLVING_EQUATIONS_ALL_H
