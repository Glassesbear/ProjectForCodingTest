#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct sCostofThrow {
    int nSource;
    int nDest;
    int nCost;
};

// Cost ������ �迭�ϱ� ���� �Լ�
bool compare(sCostofThrow a, sCostofThrow b) {
    return a.nCost < b.nCost;
}

// ���� ������ 100�� �̹Ƿ� �̸� ��� ������ �����ϰ��� ����
int parent[101] = { 0, };

// �θ� �Լ��� ã�� ���� �Լ�
// �θ� �Լ��� parent�� ���� �� x�� input���� ������
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

// ũ�罺Į �˰����� �̿��Ͽ� ����
// �ּ� Cost �������� ������ ����� ����
// root ��尡 �ٸ� ��� ��带 �����Ű��, ��Ʈ ���� union ó��
// �ش� �ڽ�Ʈ�� ���ذ��� ó���ϴ� �˰����̴�
int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    vector<sCostofThrow> edge;

    // cost �Է� �κ�
    for (int i = 0; i < costs.size(); i++) {
        sCostofThrow temp;
        temp.nSource = costs[i][0];
        temp.nDest = costs[i][1];
        temp.nCost = costs[i][2];

        edge.push_back(temp);
    }

    // cost ������ ����
    sort(edge.begin(), edge.end(), compare);

    // parent �ʱ�ȭ
    for (int i = 0; i < 101; i++) {
        parent[i] = i;
    }

    // ũ�罺Į �˰��� �̿�
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