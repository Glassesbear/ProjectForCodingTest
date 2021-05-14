#include <string>
#include <vector>
#include <algorithm>
#include <vector>
#include <stdio.h>

using namespace std;

// ���� ���� �Լ�
// ���� ���׶� ����
vector<int> NumberMaker(vector<char> &makeCard) {

    vector<int> makeNum;
    // N*M
    // ������ �̿��Ͽ� ��� ������ ���� ���Ѵ�
    // 1,2,3�� ������,
    // 1: 1, 2, 3 : temp -> 1, 12, 123 ������ makeNum�� ����
    // 2: 1, 3, 2 : temp -> 1, 13, 132 ������ ����
    // ���� �ݺ��� ��� ������ ���� ���ڴ� ��� �Ϸ�
    do {
        string temp = "";

        for (int i = 0; i < makeCard.size(); i++) {
            temp.push_back(makeCard[i]);
            makeNum.push_back(stoi(temp));
            //printf("%s\n", temp.c_str());
            //printf("%d\n", makeNum.back());
        }

    } while (next_permutation(makeCard.begin(), makeCard.end()));

    //�ߺ� �� ����
    sort(makeNum.begin(), makeNum.end());
    makeNum.erase(unique(makeNum.begin(), makeNum.end()), makeNum.end());

    return makeNum;
}

int solution(string numbers) {
    int answer = 0;

    vector<char> makeCard;
    vector<int> temp;

    // �� ���ڸ� �̾ƾ� �ϴ� �κ�
    for (int i = 0; i < numbers.size(); i++) {
        makeCard.push_back(numbers[i]);
    }
    //O(nlogn)
    sort(makeCard.begin(), makeCard.end());

    temp = NumberMaker(makeCard);

    for (auto it : temp) {
        printf("%d\n", it);
    }
    return answer;
}

int main() {
    string s = "1234";
    solution(s);
    return 0;
}