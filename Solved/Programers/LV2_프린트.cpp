#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;

    priority_queue<int, vector<int>, less<int>> pqJobs;
    queue<int> qJobs;

    // �켱 ���� �Է�
    // �Է� N * pq ���� LooN
    for (int i = 0; i < priorities.size(); i++) {
        pqJobs.push(priorities[i]);
        qJobs.push(priorities[i]);
    }


    int nLocation = location;
    while (!qJobs.empty()) {
        int nTopPriority = 0;
        nTopPriority = pqJobs.top();


        //printf("pq : %d / q : %d / location : %d\n", nTopPriority, qJobs.front(), nLocation);
        // ���� ū �켱������ qJobs �켱������ ���� ��
        if (nTopPriority == qJobs.front()) {
            qJobs.pop();
            pqJobs.pop();

            // ���++
            answer++;
            // ���� ����, ��ǥ�� location�� ó���� �� ����
            // �ƴ� ��쿡�� ��µǹǷ� location�� -- ó������� ��
            if (nLocation == 0)
                break;
            else
                nLocation--;
        }
        else {

            // �켱 ������ �ٸ� �� ó���ؾ� �� ����
            // location == 0�϶�,
            // location�� 0�ƴҶ��� ����
            if (nLocation == 0) {
                // �����̼� ��ġ�� �� �Ĺ����� �̵�
                // front���� pop �Ͽ� �ٽ� push ó���Ѵ�
                nLocation = qJobs.size() - 1;
                int temp = qJobs.front();
                qJobs.pop();
                qJobs.push(temp);
            }
            else {
                // �����̼� ��ġ�� -- ó���ϰ�
                // temp���� pop �Ͽ� �� �Ĺ����� �̵��Ѵ�
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