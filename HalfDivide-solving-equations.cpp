#include "HalfDivide-solving-equations.h"

class HalfDivide : all {
public:
    void main() {
        input();
        //������ַ����ʼ��������
        long double a, b;
        while (true) {
            cout << "���������㷶Χa b��";
            cin >> a;
            cin >> b;
            if (equation_judgment(a, b)) {
                break;
            } else {
                cout << "ERROR:a bȡֵ��������������" << endl;
            }
        }
        //���ַ�������
        while (true) {
            answer = (a + b) / 2;
            if (get_fx(a) == 0.0) {
                //��ֵΪ���
                answer = a;
                putOutAnswer();
                break;
            } else if (get_fx(b) == 0.0) {
                //��ֵΪ���
                answer = b;
                putOutAnswer();
                break;
            } else if (get_fx(answer) == 0.0) {
                //���ַ��ֵ����
                putOutAnswer();
                break;
            } else if (equation_judgment(a, answer)) {
                //���ַ���ֵȡ����ֵ
                b = answer;
            } else if (equation_judgment(answer, b)) {
                //���ַ���ֵȡ����ֵ
                a = answer;
            }
            timeLimit();
        }
    }

private:
    //�ж������a��b�Ľ���Ƿ�Ϊһ��һ��
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