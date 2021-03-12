#include <string>
#include <vector>
#include <queue>

using namespace std;
#define MaxSize 20001

// Check�� ���� ���� ����
bool check[MaxSize];

int bfs(queue<pair<int, int>>& qData, vector<vector<int>>& vData) {
    int result = 0;
    int tempMax = 0;

    while (!qData.empty()) {
        int startNum = qData.front().first;
        int count = qData.front().second;
        //printf("%d : %d\n", startNum, count);
        qData.pop();

        // �������� ����� vData�� ��ȸ�ϸ�,
        // �湮���� ���� ��쿡 count���� ++ �Ͽ�
        // queue�� ����
        for (int i = 0; i < vData[startNum].size(); i++) {
            if (check[vData[startNum][i]] == false) {
                check[vData[startNum][i]] = true; // Check ������ ǥ��

                qData.emplace(vData[startNum][i], count + 1);
                //printf("%d : %d\n", vData[startNum][i], count + 1);
                // ���� �Ÿ��� ���� ������ ���Ǹ�
                // �ش� ������ 1����, ������ tempMax�� ���� ���� ���ؼ���
                // ++ ó���� �ϸ� ���� �Ÿ��� ���� ����� ������ ��µ�
                if (tempMax < count + 1) {
                    tempMax = count + 1;
                    result = 1;
                }
                else if (tempMax == count + 1)
                    result++;
            }
        }
    }


    return result;
}

// BFS �˰��� ������ ���� BFS�� ����
int solution(int n, vector<vector<int>> edge) {
    int answer = 0;

    // �ʱ�ȭ �ϴ� �κ� �� ����� ��
    // n+1 ��ŭ vector�� n+1 �� 0�� ������ ����
    //vector<vector<int>> v(n+1, vector<int>(n+1,0));
    vector<vector<int>> v(n + 1);
    queue<pair<int, int>> q;

    for (int i = 0; i < edge.size(); i++) {
        int temp1 = edge[i][0];
        int temp2 = edge[i][1];
        v[temp1].push_back(temp2);
        v[temp2].push_back(temp1);
    }

    // �������� ����
    //q.push(1, 1);
    // emplace���� make_pair�� �̿��� Push�� ����
    q.push(make_pair(1, 1));
    check[1] = true;

    answer = bfs(q, v);

    return answer;
}

int main() {
    vector<vector<int>> e = { {3, 6},{4, 3},{3, 2},{1, 3},{1, 2},{2, 4},{5, 2}};
    int n = 6;
    printf("%d\n", solution(n, e));//3
    return 0;
}