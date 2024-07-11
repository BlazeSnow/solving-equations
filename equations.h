#ifndef SOLVING_EQUATIONS_EQUATIONS_H
#define SOLVING_EQUATIONS_EQUATIONS_H

struct equations {
    //系数
    long double coefficient;
    //幂
    long double power;
};

class all {
public:
    //方程式数组
    vector<equations> equ{};
    //答案
    long double answer;
    //迭代次数
    int times;
    //保留小数位数
    int precisionNumber;

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
