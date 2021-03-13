#include <string>
#include <vector>

using namespace std;

long long solution(int n) {
    long long answer = 0;

    // ������ ���� ��ȭ���� �� �� �ִ�
    // �� ĭ�� ���� ������ �� �ִ� �����
    // n-1ĭ���� �� ĭ �ٱ�
    // n-2ĭ���� �� ĭ �ٱ�
    // �ش� ������ ���� dynamic���� ó�� �����ϴ�
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