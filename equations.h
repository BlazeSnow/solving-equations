#ifndef SOLVING_EQUATIONS_EQUATIONS_H
#define SOLVING_EQUATIONS_EQUATIONS_H

#include <vector>
#include <iostream>

using std::vector;
using std::cout;
using std::endl;

//迭代次数限制
#define time_limit 100000

//方程式
struct equations {
    //系数
    long double coefficient = 0;
    //幂
    long double power = 0;
};

class all {
public:
    //方程式数组
    vector<equations> equ{};
    //答案
    long double answer = 0;
    //迭代次数
    int times = 1;
    //保留小数位数
    int precisionNumber = 0;

    //输入文件中的数据到数组
    void input();

    //输出答案和迭代次数
    void putOutAnswer() const;

    //迭代次数++以及判断是否超出限制
    void timeLimit();

    //计算函数的答案
    long double get_fx(long double x);
};

#endif //SOLVING_EQUATIONS_EQUATIONS_H
