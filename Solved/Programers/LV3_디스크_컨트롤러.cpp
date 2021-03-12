#include <string>
#include <vector>
#include <utility>
#include <queue>
#include <algorithm>

using namespace std;

struct compare {
    bool operator()(pair<int, int>a, pair<int, int>b) {
        return a.second > b.second;
    }
};

// 우선순위 Queue를 이용하여 문제를 풀이함
// 최초 시간 순으로 정렬
// 이후 우선 순위 삽입, 단, 시간을 Check 하여 해당 시간 전 시작시간을 가지는 작업만 추가
// 그러면 queue에서는 최소 시간을 가지는 작업을 front에 놓게 됨
// 해당 값을 더하여 평균 값을 계산
int solution(vector<vector<int>> jobs) {
    int answer = 0;
    int sum = 0;
    int time = 0;
    int j = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;
    sort(jobs.begin(), jobs.end());


    while (j < jobs.size() || !pq.empty()) {
        // job 을 queue에 입력 하는 부분
        // 해당 부분은 time 변수 상황에 따라 처리

        if (j < jobs.size() && time >= jobs[j][0]) {

            pq.push(make_pair(jobs[j][0], jobs[j][1]));
            j++;
            //printf("push : %d, %d\n", p.first, p.second);
            continue;
        }

        if (!pq.empty()) {
            time += pq.top().second;
            answer = answer + time - pq.top().first;
            pq.pop();
            //printf("pop : %d, %d\n", time, answer);
        }
        else
            time = jobs[j][0];

    }

    return answer / jobs.size();
}

int main() {
    vector<vector<int>> jobs = { {0, 3} ,{1, 9},{2, 6} };
    printf("%d\n", solution(jobs));//6
    return 0;
}