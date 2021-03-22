#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;

    priority_queue<int, vector<int>, less<int>> pqJobs;
    queue<int> qJobs;

    // 우선 순위 입력
    // 입력 N * pq 정렬 LooN
    for (int i = 0; i < priorities.size(); i++) {
        pqJobs.push(priorities[i]);
        qJobs.push(priorities[i]);
    }


    int nLocation = location;
    while (!qJobs.empty()) {
        int nTopPriority = 0;
        nTopPriority = pqJobs.top();


        //printf("pq : %d / q : %d / location : %d\n", nTopPriority, qJobs.front(), nLocation);
        // 가장 큰 우선순위와 qJobs 우선순위가 같을 때
        if (nTopPriority == qJobs.front()) {
            qJobs.pop();
            pqJobs.pop();

            // 출력++
            answer++;
            // 종료 조건, 목표한 location이 처음일 때 종료
            // 아닐 경우에는 출력되므로 location을 -- 처리해줘야 함
            if (nLocation == 0)
                break;
            else
                nLocation--;
        }
        else {

            // 우선 순위가 다를 때 처리해야 할 로직
            // location == 0일때,
            // location이 0아닐때로 구분
            if (nLocation == 0) {
                // 로케이션 위치를 최 후방으로 이동
                // front값을 pop 하여 다시 push 처리한다
                nLocation = qJobs.size() - 1;
                int temp = qJobs.front();
                qJobs.pop();
                qJobs.push(temp);
            }
            else {
                // 로케이션 위치를 -- 처리하고
                // temp값을 pop 하여 최 후방으로 이동한다
                nLocation--;
                int temp = qJobs.front();
                qJobs.pop();
                qJobs.push(temp);
            }
        }
    }
    return answer;
}

int main() {
    vector<int> p = {1,1,9,1,1,1};
    printf("%d\n", solution(p, 0));//5
    return 0;
}