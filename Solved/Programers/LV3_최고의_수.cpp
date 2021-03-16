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

    // 최고의 곱은 최대한 비슷한 수를 곱할 때, 알 수 있다.
    // 때문에 구한 몫에서
    // 나머지 갯수에서 나눌 수를 뺀 수 이외에 값에
    // 모두 1씩 더해서 전달할 때 최대의 곱이 나온다

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