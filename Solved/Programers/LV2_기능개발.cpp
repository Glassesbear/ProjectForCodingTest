#include <string>
#include <vector>
#include <stack>

using namespace std;

int calcTaskFinDay(int nProgressDay, int nSpeeds) {
    int result = 0;

    // ���� ���� �ִٸ�,
    // �������� ��� ����� �߰��Ǿ�� ��
    result = 100 - nProgressDay;
    if (result % nSpeeds == 0) {
        result = result / nSpeeds;
    }
    else {
        result = (result / nSpeeds) + 1;
    }

    return result;
}


vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    stack<int> sTaskStack;

    int nTaskFin = 0;
    int nTempCount = 1;
    // ó�� ���� ���� �߰�    
    nTaskFin = calcTaskFinDay(progresses[0], speeds[0]);
    sTaskStack.push(nTaskFin);

    // Progress�� �� ���ڿ� �����Ͽ�
    // speed �� ���̸� �̿��Ͽ� ���߿� �ʿ��� �� �� �� ���Ѵ�
    // ���� stack�� �־� �� ������ �����Ѵ�.
    for (int i = 1; i < progresses.size(); i++) {
        nTaskFin = calcTaskFinDay(progresses[i], speeds[i]);
        //printf("%d : TaskFin %d : %d\n", i, nTaskFin, nTempCount);
        // ���� �� ���� ���� ���� ���� Ŭ ���
        // pop ó�� �� push,
        // answer�� ���� count ���� �߰��ϴ� �κп� ���� ����
        if (nTaskFin > sTaskStack.top()) {
            sTaskStack.pop();
            sTaskStack.push(nTaskFin);

            answer.push_back(nTempCount);
            nTempCount = 1;
        }

        else {
            // ���� ���� ���� ���� ���
            // count�� ++ ó���Ѵ�
            nTempCount++;
        }
    }

    // size�� ���� ��� �߰� ó��
    if (sTaskStack.size() > 0) {
        sTaskStack.pop();
        answer.push_back(nTempCount);
    }

    return answer;
}

int main() {
    vector<int> p = {95,90,99,99,80,99};
    vector<int> s = { 1,1,1,1,1,1 };


    vector<int> result;
    result = solution(p,s);

    for (int i = 0; i < result.size(); i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

    return 0;
}