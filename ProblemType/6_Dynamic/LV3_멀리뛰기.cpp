#include <string>
#include <vector>

using namespace std;

long long solution(int n) {
    long long answer = 0;

    // 문제를 보면 점화식을 알 수 있다
    // 각 칸에 대해 접근할 수 있는 방법은
    // n-1칸에서 한 칸 뛰기
    // n-2칸에서 두 칸 뛰기
    // 해당 과정을 통해 dynamic으로 처리 가능하다
    long long result[2001] = { 0, };
    result[0] = 0;
    result[1] = 1;
    result[2] = 2;

    for (int i = 3; i < 2001; i++) {
        result[i] = (result[i - 1] + result[i - 2]) % 1234567;
    }

    answer = result[n];

    return answer;
}

int main() {

    printf("%lld\n", solution(4));//5

    return 0;
}