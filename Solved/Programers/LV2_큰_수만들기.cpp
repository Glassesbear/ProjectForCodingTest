#include <string>
#include <vector>
#include <stdio.h>

using namespace std;

// 큰 수 만들기 타 풀이 보고 참고하여 구현한 부분
string solution(string number, int k) {
    string answer = "";

    vector<char> result;
    int tempMaxNum = number[0];
    result.push_back(number[0]);
    for (int i = 1; i < number.size(); i++) {

        //result.push_back(number[i]);
        // 스텍을 이용하였고, k는 제거해야 하는 자릿수이며
        // 해당 횟수가 남아 있을 경우 제거,
        // 제거 하는 조건은 진입한 수보다 작을때 까지
        if ((k > 0) && (result.back() < number[i])) {

            while (k > 0 && result.size() && result.back() < number[i]) {
                result.pop_back();
                k--;
            }
            result.push_back(number[i]);

        }
        // 최초 혹은 k가 없을 경우 그냥 집어넣음
        else {
            result.push_back(number[i]);
        }
    }

    // 정답 계산 부분
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