#include <string>
#include <vector>
#include <queue>

using namespace std;
#define MaxSize 20001

// Check를 위한 전역 변수
bool check[MaxSize];

int bfs(queue<pair<int, int>>& qData, vector<vector<int>>& vData) {
    int result = 0;
    int tempMax = 0;

    while (!qData.empty()) {
        int startNum = qData.front().first;
        int count = qData.front().second;
        //printf("%d : %d\n", startNum, count);
        qData.pop();

        // 시작점에 저장된 vData를 순회하며,
        // 방문하지 않은 경우에 count값을 ++ 하여
        // queue에 저장
        for (int i = 0; i < vData[startNum].size(); i++) {
            if (check[vData[startNum][i]] == false) {
                check[vData[startNum][i]] = true; // Check 시잠을 표시

                qData.emplace(vData[startNum][i], count + 1);
                //printf("%d : %d\n", vData[startNum][i], count + 1);
                // 가장 거리가 많은 지점이 계산되면
                // 해당 지점은 1개고, 나머지 tempMax와 같은 값에 대해서만
                // ++ 처리를 하면 같은 거리를 가진 노드의 갯수가 출력됨
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

// BFS 알고리즘 연습을 위해 BFS로 구현
int solution(int n, vector<vector<int>> edge) {
    int answer = 0;

    // 초기화 하는 부분 잘 사용할 것
    // n+1 만큼 vector의 n+1 을 0의 값으로 세팅
    //vector<vector<int>> v(n+1, vector<int>(n+1,0));
    vector<vector<int>> v(n + 1);
    queue<pair<int, int>> q;

    for (int i = 0; i < edge.size(); i++) {
        int temp1 = edge[i][0];
        int temp2 = edge[i][1];
        v[temp1].push_back(temp2);
        v[temp2].push_back(temp1);
    }

    // 시작지점 설정
    //q.push(1, 1);
    // emplace에서 make_pair를 이용한 Push로 수정
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