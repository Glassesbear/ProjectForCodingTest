#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int s) {
    vector<int> answer;

    if (s - n < 0) {
        answer.push_back(-1);
        return answer;
    }

    int nShare = s / n;
    int nReminder = s % n;
    int nAddPointNum = n - nReminder;

    // �ְ��� ���� �ִ��� ����� ���� ���� ��, �� �� �ִ�.
    // ������ ���� �򿡼�
    // ������ �������� ���� ���� �� �� �̿ܿ� ����
    // ��� 1�� ���ؼ� ������ �� �ִ��� ���� ���´�

    for (int i = 0; i < n; i++) {

        if (nAddPointNum > 0) {
            answer.push_back(nShare);
            nAddPointNum--;
        }
        else {
            answer.push_back(nShare + 1);
        }

    }

    return answer;
}

int main() {
    solution(2, 9);
    return 0;
}