#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct sCostofThrow {
    int nSource;
    int nDest;
    int nCost;
};

// Cost 순으로 배열하기 위한 함수
bool compare(sCostofThrow a, sCostofThrow b) {
    return a.nCost < b.nCost;
}

// 섬의 갯수가 100개 이므로 이를 멤버 변수로 관리하고자 선언
int parent[101] = { 0, };

// 부모 함수를 찾기 위한 함수
// 부모 함수의 parent와 물을 수 x를 input으로 가진다
int find_parent(int x) {

    if (parent[x] != x) {
        parent[x] = find_parent(parent[x]);
    }

    return parent[x];
}

void union_parent(int a, int b) {

    int temp1 = find_parent(a);
    int temp2 = find_parent(b);


    if ( temp1 < temp2 ) {
        parent[temp2] = temp1;
    }
    else
        parent[temp1] = temp2;
}

// 크루스칼 알고리즘을 이용하여 연산
// 최소 Cost 기준으로 노드들을 묶어가며 연산
// root 노드가 다를 경우 노드를 연결시키고, 루트 노드로 union 처리
// 해당 코스트를 더해가며 처리하는 알고리즘이다
int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    vector<sCostofThrow> edge;

    // cost 입력 부분
    for (int i = 0; i < costs.size(); i++) {
        sCostofThrow temp;
        temp.nSource = costs[i][0];
        temp.nDest = costs[i][1];
        temp.nCost = costs[i][2];

        edge.push_back(temp);
    }

    // cost 순으로 정렬
    sort(edge.begin(), edge.end(), compare);

    // parent 초기화
    for (int i = 0; i < 101; i++) {
        parent[i] = i;
    }

    // 크루스칼 알고리즘 이용
    for (int i = 0; i < edge.size(); i++) {
        sCostofThrow temp;
        temp = edge[i];

        if (find_parent(temp.nSource) != find_parent(temp.nDest)) {
            union_parent(temp.nSource, temp.nDest);
            answer += temp.nCost;
        }
    }

    return answer;
}

int main() {
    vector<vector<int>> costs = { {0,1,5},{1,2,3},{2,3,3},{3,1,2},{3,0,4},{2,4,6},{4,0,7} };
    int n = 5;
    printf("%d\n", solution(n, costs));
    return 0;
}