#include <string>
#include <vector>

using namespace std;

// ���� ���Ǹ� ���� ���� ������ ����
vector<vector<int>> answer;

void hanoi(int n, int from, int to, int temp) {

    vector<int> t;
    t.push_back(from);
    t.push_back(to);

    // ���� ����
    if (n == 1) {
        answer.push_back(t);
        return;
    }
    else {
        // ���� 1->3�� ���� ������, 1->2�� ���� �����ؾ� �ϹǷ�
        // �ش� �κп� ���� ��������� ȣ����
        // 1->2
        hanoi(n - 1, from, temp, to);

        // ��� ȣ���� ������, 1->3���� �����ϴ� �κп� ���� ���
        answer.push_back(t);

        // ���� 2->3���� �����ϴ� ���� ����
        hanoi(n - 1, temp, to, from);
    }
}

vector<vector<int>> solution(int n) {
    hanoi(n, 1, 3, 2);
    return answer;
}

int main() {
    vector<vector<int>> temp;
    temp = solution(2);

    for (auto it : temp){
        for (auto it2 : it) {
            printf("%d ", it2);
        }
        printf("\n");
    }

    return 0;
}