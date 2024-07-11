#ifndef SOLVING_EQUATIONS_SOLVING_EQUATIONS_H
#define SOLVING_EQUATIONS_SOLVING_EQUATIONS_H

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
    void main() ;
};

//牛顿迭代法
class Newton : public all {
public:
    void main() ;
};

//弦截法
class Secant_method : public all {
public:
    void main() ;
};

#endif //SOLVING_EQUATIONS_SOLVING_EQUATIONS_H
