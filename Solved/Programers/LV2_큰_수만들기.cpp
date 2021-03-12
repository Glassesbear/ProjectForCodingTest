#include <string>
#include <vector>
#include <stdio.h>

using namespace std;

// ū �� ����� Ÿ Ǯ�� ���� �����Ͽ� ������ �κ�
string solution(string number, int k) {
    string answer = "";

    vector<char> result;
    int tempMaxNum = number[0];
    result.push_back(number[0]);
    for (int i = 1; i < number.size(); i++) {

        //result.push_back(number[i]);
        // ������ �̿��Ͽ���, k�� �����ؾ� �ϴ� �ڸ����̸�
        // �ش� Ƚ���� ���� ���� ��� ����,
        // ���� �ϴ� ������ ������ ������ ������ ����
        if ((k > 0) && (result.back() < number[i])) {

            while (k > 0 && result.size() && result.back() < number[i]) {
                result.pop_back();
                k--;
            }
            result.push_back(number[i]);

        }
        // ���� Ȥ�� k�� ���� ��� �׳� �������
        else {
            result.push_back(number[i]);
        }
    }

    // ���� ��� �κ�
    for (auto it : result) {
        answer += it;
    }

    return answer;
}

int main() {
    string temp = "4177252841";
        printf("%s\n",solution(temp, 4).c_str());
    return 0;
}