#include <string>
#include <vector>

using namespace std;

// ���̳��� ����,
// fn = fn-1 + fn-2 �� ��ȭ���� �˾Ƴ��°��� ��ǥ
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