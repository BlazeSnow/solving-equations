#include <iostream>
#include <fstream>
#include <filesystem>
#include <vector>

using std::cout;
using std::endl;
using std::cin;
using std::vector;
using std::fstream;
using std::ios;
using std::setprecision;

#include "equations.h"

//弦截法
class Secant_method : all {
public:
    void main() {
        input();
        cout << "请输入x0和x1：" << endl;
        cin >> x0 >> x1;
        while (true) {
            long double temp;
            temp = get_Secant(x0, x1);
            x0 = x1;
            x1 = temp;
            if (x0 == x1) {
                answer = x1;
                putOutAnswer();
                break;
            } else {
                timeLimit();
            }
        }
    }

private:
    long double x0 = 0;
    long double x1 = 0;

    //弦截法
    long double get_Secant(long double num0, long double num1) {
        long double answer;
        answer = num1 - get_fx(num1) * (num1 - num0) / (get_fx(num1) - get_fx(num0));
        return answer;
    }
};