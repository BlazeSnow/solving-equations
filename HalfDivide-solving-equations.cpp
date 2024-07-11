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

#include "HalfDivide-solving-equations.h"
#include "equations.h"

class all;

class HalfDivide : public all {
public:
    void main() {
        input();
        //输入二分法的最开始的两个数
        long double a, b;
        while (true) {
            cout << "请输入运算范围a b：";
            cin >> a;
            cin >> b;
            if (equation_judgment(a, b)) {
                break;
            } else {
                cout << "ERROR:a b取值错误，请重新输入" << endl;
            }
        }
        //二分法主程序
        while (true) {
            answer = (a + b) / 2;
            if (get_fx(a) == 0.0) {
                //左值为结果
                answer = a;
                putOutAnswer();
                break;
            } else if (get_fx(b) == 0.0) {
                //右值为结果
                answer = b;
                putOutAnswer();
                break;
            } else if (get_fx(answer) == 0.0) {
                //二分法分到结果
                putOutAnswer();
                break;
            } else if (equation_judgment(a, answer)) {
                //二分法中值取代右值
                b = answer;
            } else if (equation_judgment(answer, b)) {
                //二分法中值取代左值
                a = answer;
            }
            timeLimit();
        }
    }

private:
    //判断输入的a和b的结果是否为一正一负
    bool equation_judgment(const long double a, const long double b) {
        long double answer_a = get_fx(a);
        long double answer_b = get_fx(b);
        if (((answer_a <= 0) && (answer_b >= 0)) || (answer_a >= 0) && (answer_b <= 0)) {
            return true;
        } else {
            return false;
        }
    }
};