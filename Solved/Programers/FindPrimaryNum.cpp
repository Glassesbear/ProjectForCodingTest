#include <string>
#include <vector>
#include <algorithm>
#include <vector>

using namespace std;

bool IsPrime(int number) {

    // 2 ������ ���� �Ҽ� check�� ���� �ʾƵ� ��
    if (number < 2)
        return false;

    for (int i = 2; i * i <= number; i++) {

        // �Ҽ� �Ǻ��ϴ� �κ�
        if (number % i == 0) {
            return false;
        }
    }

    return true;
}

int solution(string numbers) {
    int answer = 0;

    vector<char> makeCard;
    vector<int> makeNum;

    // �� ���ڸ� �̾ƾ� �ϴ� �κ�
    for (int i = 0; i < numbers.size(); i++) {
        makeCard.push_back(numbers[i]);
    }
    //O(nlogn)
    sort(makeCard.begin(), makeCard.end());

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

    for (auto it : makeNum) {
        // �� ���ڿ� ���� �Ҽ� �Ǻ��ϴ� �Լ��� ȣ���Ͽ�
        // ��� �Ҽ��� ����� ������ �Ǵ�
        if (IsPrime(it)) {
            answer++;
        }
    }



    return answer;
}