#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    string answer = "";

    vector<char> result;
    int tempMaxNum = number[0];
    result.push_back(number[0]);
    for (int i = 1; i < number.size(); i++) {

        //result.push_back(number[i]);
        if ((k > 0) && (result.back() < number[i])) {

            while (k > 0 && result.size() && result.back() < number[i]) {
                result.pop_back();
                k--;
            }
            result.push_back(number[i]);

        }
        else {
            result.push_back(number[i]);
        }
    }

    // k 남았을 때, 뒤에서 빼는 로직 추가
    if (k > 0) {
        for (int i = 0; i < k; i++) {
            result.pop_back();
        }
    }

    // 정답 계산 부분
    for (auto it : result) {
        answer += it;
    }

    return answer;
}

int main() {
    string result;
    result = solution("4177252841", 4);// 775841

    printf("%s\n", result.c_str());

    return 0;
}