#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

// unordered map에 각 계산한 값을 삽입하여
// 해당 값이 있는지 Check 하여 동작을 수행
int solution(int N, int number) {
    int answer = -1;

    // 8개 까지만 동작
    unordered_set<int> s[8];
    int base = 0;
    //초기 N으로 만들 수 있는 수들을 적재
    for (int i = 0; i < 8; i++) {
        base = 10 * base + 1;
        s[i].insert(base * N);
    }
    //다음 수가 만들어지는 과정은
    //현재수 = 이전수 + - * / 이전수
    //현재수 = 이전수-1 + - * / 이전수 + 1
    // ... 형태로 만들어짐
    for (int i = 0; i < 8; i++) {// 총 연산 횟수
        for (int j = 0; j < i; j++) {// 해당 연산 횟수의 s[j]와 s[i-j-1]을 이용하여 모든 수를 만들어 Check
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