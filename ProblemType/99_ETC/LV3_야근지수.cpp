#include <string>
#include <vector>
#include <queue>

using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;

    priority_queue<long long, vector<long long>> pq;

    // 입력부분
    for (int i = 0; i < works.size(); i++) {
        pq.push((long long)works[i]);
    }

    // 순환하며, 가장 큰 야근시간을 1씩 깎는다면,
    // 최소 시간이 만들어질 것
    while (n > 0 && !pq.empty()) {
        long long temp = pq.top();
        pq.pop();

        temp--;
        if (temp > 0) {
            pq.push(temp);
        }

        n--;
    }

    while (!pq.empty()) {
        long long temp = pq.top();
        pq.pop();

        temp = temp * temp;
        answer += temp;
    }

    return answer;
}

int main() {
    int n = 3;
    vector<int> works = { 1,1 };
    printf("%lld\n", solution(n, works));
    return 0;
}
