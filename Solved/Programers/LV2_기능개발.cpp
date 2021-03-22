#include <string>
#include <vector>
#include <stack>

using namespace std;

int calcTaskFinDay(int nProgressDay, int nSpeeds) {
    int result = 0;

    // 남은 날이 있다면,
    // 다음날로 계산 결과가 추가되어야 함
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
    // 처음 비교할 값을 추가    
    nTaskFin = calcTaskFinDay(progresses[0], speeds[0]);
    sTaskStack.push(nTaskFin);

    // Progress에 각 인자에 접근하여
    // speed 와 차이를 이용하여 개발에 필요한 일 수 를 구한다
    // 이후 stack에 넣어 각 과정을 진행한다.
    for (int i = 1; i < progresses.size(); i++) {
        nTaskFin = calcTaskFinDay(progresses[i], speeds[i]);
        //printf("%d : TaskFin %d : %d\n", i, nTaskFin, nTempCount);
        // 이전 값 보다 새로 계산된 값이 클 경우
        // pop 처리 후 push,
        // answer에 계산된 count 값을 추가하는 부분에 대한 로직
        if (nTaskFin > sTaskStack.top()) {
            sTaskStack.pop();
            sTaskStack.push(nTaskFin);

            answer.push_back(nTempCount);
            nTempCount = 1;
        }

        else {
            // 현재 계산된 값이 작을 경우
            // count만 ++ 처리한다
            nTempCount++;
        }
    }

    // size가 남을 경우 추가 처리
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