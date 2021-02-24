#include <string>
#include <vector>
#include <stack>
#include <stdio.h>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;

    stack<int> s;
    int temp = 0;
    int tempIdx = 0;

    // �Է� ���� moves ��ŭ �����ϰ� ����
    for (int i = 0; i < moves.size(); i++) {
        temp = 0;
        tempIdx = moves[i] - 1;

        // ũ������ �����ͼ� ������ �̴� �κ�
        // �� ������ �����̱� ������, tempIdx ������ ������ �����ϵ��� ����
        // �ϳ� ������ ������ �����̱� ������ break�� �̿�
        for (int j = 0; j < board.size(); j++) {
            if (board[j][tempIdx]) {
                temp = board[j][tempIdx];
                board[j][tempIdx] = 0;
                break;
            }
        }
        //printf("%d ", temp);

        // Stack�� Check �ϸ� Count�� ���� �κ�
        if (s.size() > 0 && s.top() == temp) {

            answer += 2;
            printf("%d : %d : %d\n", i, s.top(), answer);
            s.pop();
        }
        else {
            s.push(temp);
        }
    }

    return answer;
}

int main() {

    vector<vector<int>> board = { 
        { 0,0,0,0,0 }, 
        { 0,0,1,0,3 }, 
        { 0,2,5,0,1 }, 
        { 3,2,4,4,2 }, 
        { 3,5,1,3,1 } 
    };
    vector<int> moves = { 1,5,3,5,1,2,1,4 };
    
    printf("%d\n", solution(board, moves));

    return 0;
}