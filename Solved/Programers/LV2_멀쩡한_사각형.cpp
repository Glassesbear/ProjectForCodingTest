#include <stdio.h>

long long solution(int w, int h) {
    long long answer = 0;
    long long y = 0;

    // 수학적으로 기울기를 이용
    // 해당 높이 전까지 정수가 가질수 있는 최대 정수로 판단됨
    for (long long i = 0; i < w; i++) {
        // 기울기 계산
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