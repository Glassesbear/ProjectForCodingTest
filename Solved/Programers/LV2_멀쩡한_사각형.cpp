#include <stdio.h>

long long solution(int w, int h) {
    long long answer = 0;
    long long y = 0;

    // ���������� ���⸦ �̿�
    // �ش� ���� ������ ������ ������ �ִ� �ִ� ������ �Ǵܵ�
    for (long long i = 0; i < w; i++) {
        // ���� ���
        y = (h * i) / w;
        //printf("%d : %d\n", i , y);
        if (y != 0) {
            answer = answer + y;
        }
    }

    return 2 * answer;
}

int main() {

    int W = 8;
    int H = 12;

    printf("%lld\n", solution(W,H));//80

    return 0;
}