#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

// unordered map�� �� ����� ���� �����Ͽ�
// �ش� ���� �ִ��� Check �Ͽ� ������ ����
int solution(int N, int number) {
    int answer = -1;

    // 8�� ������ ����
    unordered_set<int> s[8];
    int base = 0;
    //�ʱ� N���� ���� �� �ִ� ������ ����
    for (int i = 0; i < 8; i++) {
        base = 10 * base + 1;
        s[i].insert(base * N);
    }
    //���� ���� ��������� ������
    //����� = ������ + - * / ������
    //����� = ������-1 + - * / ������ + 1
    // ... ���·� �������
    for (int i = 0; i < 8; i++) {// �� ���� Ƚ��
        for (int j = 0; j < i; j++) {// �ش� ���� Ƚ���� s[j]�� s[i-j-1]�� �̿��Ͽ� ��� ���� ����� Check
            for (auto& op1 : s[j]) {
                for (auto& op2 : s[i - j - 1]) {
                    s[i].insert(op1 + op2);
                    s[i].insert(op1 - op2);
                    s[i].insert(op1 * op2);
                    if (op2 != 0) {
                        s[i].insert(op1 / op2);
                    }
                }
            }
        }
        if (s[i].count(number) > 0) {
            answer = i + 1;
            break;
        }
    }

    return answer;
}

int main() {
    int N = 5;
    int number = 12;
    printf("%d\n", solution(N, number));//4
    return 0;
}