#ifndef SOLVING_EQUATIONS_MAIN_H
#define SOLVING_EQUATIONS_MAIN_H

#include <vector>

//方程式
struct solving {
    //系数
    long double coefficient = 0;
    //幂
    long double power = 0;
};

//迭代次数限制
#define time_limit 100000

class solving_equations {
public:
    //方程式数组
    std::vector<solving> equ{};
    //答案
    long double answer = 0;
    //保留小数位数
    int precisionNumber = 0;
    //迭代次数
    int times = 1;

    void input();

    solving_equations();

    //输出答案和迭代次数
    void putOutAnswer() const;

    //迭代次数++以及判断是否超出限制
    void timeLimit();

    //计算函数的答案
    long double get_fx(long double x);
};

#endif //SOLVING_EQUATIONS_MAIN_H
