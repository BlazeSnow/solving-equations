#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <filesystem>
#include <fstream>
#include <vector>

#ifdef _WIN32
#include <windows.h>
#endif

using namespace std;

#define time_limit 100000

void clearConsole() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void enterToContinue() {
    printf("按回车键继续...");
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
    }
    getchar();
}

struct equations {
    long double coefficient = 0;
    long double power = 0;
};

class All {
public:
    vector<equations> equ{};
    long double answer = 0;
    int times = 1;
    int precisionNumber = 0;

    void input() {
        fstream file("solving-equations.txt", ios::in);
        if (file.is_open()) {
            equations temp{};
            for (int i = 0;; i++) {
                file >> temp.coefficient;
                file >> temp.power;
                equ.push_back(temp);
                if (file.eof()) {
                    break;
                }
            }
            file.close();
            printf("读取文件成功\n");
            printf("文件路径：%s\n", std::filesystem::current_path().string().c_str());
            printf("方程：f(x) = ");
            for (auto &i: equ) {
                printf("%+Lf x %Lf ", i.coefficient, i.power);
            }
            printf("\n");
            printf("输入精度（保留几位小数）：");
            scanf("%d", &precisionNumber);
            long double precision = pow(10, -precisionNumber);
            printf("精度为%.*Lf\n", precisionNumber, precision);
        }
    }

    void putOutAnswer() const {
        printf("answer = %.*Lf\n", precisionNumber, answer);
        printf("迭代次数%d次\n", times);
        enterToContinue();
    }

    void timeLimit() {
        times++;
        if (times > time_limit) {
            printf("迭代次数超过%d次\n", time_limit);
            printf("已终止程序\n");
            enterToContinue();
            exit(1);
        }
    }

    long double getFx(long double x) {
        long double y = 0;
        for (auto &i: equ) {
            y += i.coefficient * (pow(x, i.power));
        }
        return y;
    }
};

class Secant : public All {
public:
    void main() {
        input();
        printf("请输入x0和x1：\n");
        scanf("%Lf %Lf", &x0, &x1);
        while (true) {
            long double temp = getSecant(x0, x1);
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

    long double getSecant(long double num0, long double num1) {
        return num1 - getFx(num1) * (num1 - num0) / (getFx(num1) - getFx(num0));
    }
};

class Newton : public All {
public:
    void main() {
        input();
        printf("请输入初值：");
        scanf("%Lf", &answer);
        while (true) {
            if (equationNewton(answer) == answer) {
                putOutAnswer();
                break;
            }
            answer = equationNewton(answer);
            timeLimit();
        }
    }

private:
    long double getDerivation(long double x) {
        long double y = 0;
        for (auto &i: equ) {
            y += (i.coefficient * i.power) * (pow(x, i.power - 1));
        }
        return y;
    }

    long double equationNewton(long double x) {
        return x - (getFx(x) / getDerivation(x));
    }
};

class HalfDivide : public All {
public:
    void main() {
        input();
        long double a, b;
        while (true) {
            printf("请输入运算范围a b：");
            scanf("%Lf %Lf", &a, &b);
            if (equationJudgment(a, b)) {
                break;
            } else {
                printf("ERROR:a b取值错误，请重新输入\n");
            }
        }
        while (true) {
            answer = (a + b) / 2;
            if (getFx(a) == 0.0) {
                answer = a;
                putOutAnswer();
                break;
            } else if (getFx(b) == 0.0) {
                answer = b;
                putOutAnswer();
                break;
            } else if (getFx(answer) == 0.0) {
                putOutAnswer();
                break;
            } else if (equationJudgment(a, answer)) {
                b = answer;
            } else if (equationJudgment(answer, b)) {
                a = answer;
            }
            timeLimit();
        }
    }

private:
    bool equationJudgment(const long double a, const long double b) {
        long double answer_a = getFx(a);
        long double answer_b = getFx(b);
        if (((answer_a <= 0) && (answer_b >= 0)) || (answer_a >= 0) && (answer_b <= 0)) {
            return true;
        } else {
            return false;
        }
    }
};

int main() {
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
#endif

    clearConsole();
    printf("Copyright (C) 2024-2026 BlazeSnow.\n");
    printf("https://github.com/BlazeSnow/solving-equations\n\n");
    fstream file("solving-equations.txt", ios::in);
    if (file.is_open()) {
        file.close();
        int panduan = -1;
        printf("二分法(0)\n");
        printf("牛顿迭代法(1)\n");
        printf("弦截法(2)\n");
        printf("输入：");
        scanf("%d", &panduan);
        if (panduan == 0) {
            HalfDivide a;
            a.main();
        } else if (panduan == 1) {
            Newton a;
            a.main();
        } else if (panduan == 2) {
            Secant a;
            a.main();
        } else {
            printf("ERROR:输入内容不合法，请重新开始程序\n");
            enterToContinue();
            return -1;
        }
    } else {
        fstream file1("solving-equations.txt", ios::out);
        if (file1.is_open()) {
            file1.close();
            printf("已创建新文件\"solving-equations.txt\"。\n");
            printf("文件路径:%s\n", std::filesystem::current_path().string().c_str());
            enterToContinue();
        } else {
            printf("ERROR:创建文件失败\n");
            enterToContinue();
            return -1;
        }
    }
    return 0;
}
