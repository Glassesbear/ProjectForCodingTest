#include <string>
#include <vector>

using namespace std;

// 구현 편의를 위해 전역 변수로 선언
vector<vector<int>> answer;

void hanoi(int n, int from, int to, int temp) {

    vector<int> t;
    t.push_back(from);
    t.push_back(to);

    // 종료 조건
    if (n == 1) {
        answer.push_back(t);
        return;
    }
    else {
        // 최초 1->3에 대해 적재전, 1->2로 고리를 전달해야 하므로
        // 해당 부분에 대해 재귀적으로 호출함
        // 1->2
        hanoi(n - 1, from, temp, to);

        // 재귀 호출이 끝나면, 1->3으로 전달하는 부분에 대해 기록
        answer.push_back(t);

        // 이후 2->3으로 전달하는 로직 수행
        hanoi(n - 1, temp, to, from);
    }
}

vector<vector<int>> solution(int n) {
    hanoi(n, 1, 3, 2);
    return answer;
}

int main() {
    vector<vector<int>> temp;
    temp = solution(2);

    for (auto it : temp){
        for (auto it2 : it) {
            printf("%d ", it2);
        }
        printf("\n");
    }

    return 0;
}