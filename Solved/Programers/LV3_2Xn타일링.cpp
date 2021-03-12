#include <string>
#include <vector>

using namespace std;

// 다이나믹 문제,
// fn = fn-1 + fn-2 의 점화식을 알아내는것이 목표
int solution(int n) {
    int answer = 0;

    int nResult[60001] = { 0, };
    nResult[1] = 1;
    nResult[2] = 2;


    for (int i = 3; i < 60001; i++) {
        nResult[i] = (nResult[i - 1] + nResult[i - 2]) % 1000000007;
    }

    answer = nResult[n];

    return answer;
}

int main() {
    printf("%d\n", solution(4));//5
    return 0;
}