#include <string>
#include <vector>
#include <algorithm>
#include <vector>
#include <stdio.h>

using namespace std;

// 조합 생성 함수
// 추후 코테때 참조
vector<int> NumberMaker(vector<char> &makeCard) {

    vector<int> makeNum;
    // N*M
    // 순열을 이용하여 모든 조합의 수를 구한다
    // 1,2,3이 있을때,
    // 1: 1, 2, 3 : temp -> 1, 12, 123 순으로 makeNum로 저장
    // 2: 1, 3, 2 : temp -> 1, 13, 132 순으로 저장
    // 이하 반복시 모든 순열에 대한 숫자는 계산 완료
    do {
        string temp = "";

        for (int i = 0; i < makeCard.size(); i++) {
            temp.push_back(makeCard[i]);
            makeNum.push_back(stoi(temp));
            //printf("%s\n", temp.c_str());
            //printf("%d\n", makeNum.back());
        }

    } while (next_permutation(makeCard.begin(), makeCard.end()));

    //중복 값 제거
    sort(makeNum.begin(), makeNum.end());
    makeNum.erase(unique(makeNum.begin(), makeNum.end()), makeNum.end());

    return makeNum;
}

int solution(string numbers) {
    int answer = 0;

    vector<char> makeCard;
    vector<int> temp;

    // 각 숫자를 뽑아야 하는 부분
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