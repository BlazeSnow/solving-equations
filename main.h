#ifndef SOLVING_EQUATIONS_MAIN_H
#define SOLVING_EQUATIONS_MAIN_H

#include <vector>

using std::vector;

//方程式
struct solving {
    //系数
    long double coefficient = 0;
    //幂
    long double power = 0;
};

struct equations {
    //方程式
    vector<solving> equ{};
    //答案
    long double answer = 0;
};

struct solving_equations_data {
    //保留小数位数
    int precisionNumber = 0;
    //迭代次数
    int times = 0;
    //迭代次数限制
    const int time_limit = 10000;
};

class solving_equations {
public:
    solving_equations();

    //输出答案和迭代次数
    static void putOutAnswer(const equations& equations, solving_equations_data data) ;

    //迭代次数++以及判断是否超出限制
    static void timeLimit(solving_equations_data data);

    //计算函数的答案
    static long double get_fx(const equations& equations, long double x);
};

#endif //SOLVING_EQUATIONS_MAIN_H
