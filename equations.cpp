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

//������������
#define time_limit 100000

//����ʽ
struct equations {
    //ϵ��
    long double coefficient = 0;
    //��
    long double power = 0;
};

class all {
public:
    //����ʽ����
    vector<equations> equ{};
    //��
    long double answer = 0;
    //��������
    int times = 1;
    //����С��λ��
    int precisionNumber = 0;

    //�����ļ��е����ݵ�����
    void input() {
        fstream file("BlazeSnow �ⷽ��.txt", ios::in);
        if (file.is_open()) {
            //��ȡ�ļ�
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
            //���·��
            cout << "��ȡ�ļ��ɹ�" << endl;
            std::filesystem::path path = std::filesystem::current_path();
            cout << "�ļ�·����" << path << endl;
            //���ԭ����
            cout << "���̣�f(x) = ";
            for (auto &i: equ) {
                cout << setiosflags(ios::showpos);
                cout << i.coefficient;
                cout << resetiosflags(ios::showpos);
                cout << " x ";
                cout << i.power << " ";
            }
            cout << endl;
            //���뾫��
            cout << "���뾫�ȣ�������λС������";
            cin >> precisionNumber;
            long double precision = pow(10, -precisionNumber);
            cout << setprecision(precisionNumber);
            cout << "����Ϊ" << precision << endl;
        }
    }

    //����𰸺͵�������
    void putOutAnswer() const {
        cout << "answer = " << answer << endl;
        cout << "��������" << times << "��" << endl;
    }

    //��������++�Լ��ж��Ƿ񳬳�����
    void timeLimit() {
        times++;
        if (times > time_limit) {
            cout << "������������" << 10000000 << "��" << endl;
            cout << "����ֹ����" << endl;
            abort();
        }
    }

    //���㺯���Ĵ�
    long double get_fx(long double x) {
        long double y = 0;
        for (auto &i: equ) {
            y += i.coefficient * (pow(x, i.power));
        }
        return y;
    }
};