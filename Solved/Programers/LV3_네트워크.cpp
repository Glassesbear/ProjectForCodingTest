#include <string>
#include <vector>

using namespace std;

bool dfs(vector<vector<int>>& v, int i) {

    if (!v[i][i]) {
        return false;
    }

    v[i][i] = 0;
    for (int j = 0; j < v[i].size(); j++) {
        if (v[i][j])
            dfs(v, j);
    }
    return true;
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;

    for (int i = 0; i < computers.size(); i++) {
        if (dfs(computers, i)) {
            answer++;
        }
    }

    return answer;
}

// DFS�� ���� 1�� Check �� �κп� ���� �� �̵��ϴ� ���·� ������
// ����Ǿ��� ����, True�� ���ʷ� ���޵Ǹ�, �ش� ��쿡�� ++ �Ͽ� ������ ����
int main() {
    int i = 3;
    vector<vector<int>> v = { {1,1,0},{1,1,0},{0,0,1} };
    printf("%d\n", solution(i, v));
    return 0;
}