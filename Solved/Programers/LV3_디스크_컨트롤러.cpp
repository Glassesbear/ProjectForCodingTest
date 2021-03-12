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

// �켱���� Queue�� �̿��Ͽ� ������ Ǯ����
// ���� �ð� ������ ����
// ���� �켱 ���� ����, ��, �ð��� Check �Ͽ� �ش� �ð� �� ���۽ð��� ������ �۾��� �߰�
// �׷��� queue������ �ּ� �ð��� ������ �۾��� front�� ���� ��
// �ش� ���� ���Ͽ� ��� ���� ���
int solution(vector<vector<int>> jobs) {
    int answer = 0;
    int sum = 0;
    int time = 0;
    int j = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;
    sort(jobs.begin(), jobs.end());


    while (j < jobs.size() || !pq.empty()) {
        // job �� queue�� �Է� �ϴ� �κ�
        // �ش� �κ��� time ���� ��Ȳ�� ���� ó��

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