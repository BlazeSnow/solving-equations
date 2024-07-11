#include <iostream>
#include <fstream>
#include <filesystem>
#include "HalfDivide-solving-equations.h"
#include "Secant_method-solving-equations.h"
#include "Newton-sloving-equations.h"

using namespace std;

int main() {
    fstream file("sloving-equations.txt", ios::in);
    if (file.is_open()) {
        //如果有文件
        file.close();
        //判断使用哪种方法
        int panduan = -1;
        cout << "使用二分法(0)，牛顿迭代法(1)，弦截法(2)：";
        cin >> panduan;
        if (panduan == 0) {
            HalfDivide a;
            a.main();
        } else if (panduan == 1) {
            Newton a;
            a.main();
        } else if (panduan == 2) {
            Secant_method a;
            a.main();
        } else {
            cout << "ERROR:输入内容不合法，请重新开始程序" << endl;
            return -1;
        }
    } else {
        //如果没有文件
        fstream file1("sloving-equations.txt", ios::out);
        if (file1.is_open()) {
            file1.close();
            cout << "已创建新文件\"sloving-equations.txt\"。" << endl;
            //打印文件路径,path变量用于存储路径
            std::filesystem::path path = std::filesystem::current_path();
            cout << "文件路径:" << path << endl;
        } else {
            //创建文件失败
            cout << "ERROR:创建文件失败" << endl;
            return -1;
        }
    }
    return 0;
}
