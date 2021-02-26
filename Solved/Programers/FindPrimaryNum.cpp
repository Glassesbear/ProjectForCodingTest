#include <string>
#include <vector>
#include <algorithm>
#include <vector>

using namespace std;

bool IsPrime(int number) {

    // 2 이하일 때는 소수 check를 하지 않아도 됨
    if (number < 2)
        return false;

    for (int i = 2; i * i <= number; i++) {

        // 소수 판별하는 부분
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

    // 각 숫자를 뽑아야 하는 부분
    for (int i = 0; i < numbers.size(); i++) {
        makeCard.push_back(numbers[i]);
    }
    //O(nlogn)
    sort(makeCard.begin(), makeCard.end());

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

    for (auto it : makeNum) {
        // 각 숫자에 대해 소수 판별하는 함수를 호출하여
        // 몇개의 소수가 만들어 졌는지 판단
        if (IsPrime(it)) {
            answer++;
        }
    }



    return answer;
}