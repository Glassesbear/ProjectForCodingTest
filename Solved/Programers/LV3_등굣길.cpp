#include <string>
#include <vector>
#include <queue>

using namespace std;



int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    int check[101][101];

    // �ʱ�ȭ
    for (int i = 0; i < 101; i++) {
        for (int j = 0; j < 101; j++) {
            check[i][j] = 1;
        }
    }

    // puddle ���� ó��
    for (int i = 0; i < puddles.size(); i++) {
        check[puddles[i][0]][puddles[i][1]] = 0;
    }

    for (int i = 2; i <= n; i++) { //����ĭ, ��ĭ �� ���س����鼭 �� ���ϱ�
        for (int j = 2; j <= m; j++) {
            if (check[i][j] != 0) //�������� ����
                check[i][j] = (check[i - 1][j] + check[i][j - 1]) % 1000000007;
        }
    }


    answer = check[n][m];
    return answer;
}

int main() {
    int m = 4;
    int n = 3;
    vector<vector<int>> puddles = { {2,2}};
    printf("%d\n", solution(m, n, puddles));
    return 0;
}