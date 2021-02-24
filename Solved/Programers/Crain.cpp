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

    // 입력 받은 moves 만큼 동작하게 만듦
    for (int i = 0; i < moves.size(); i++) {
        temp = 0;
        tempIdx = moves[i] - 1;

        // 크레인이 내려와서 인형을 뽑는 부분
        // 열 단위로 움직이기 때문에, tempIdx 고정된 값으로 동작하도록 구성
        // 하나 뽑으면 동작이 종료이기 때문에 break를 이용
        for (int j = 0; j < board.size(); j++) {
            if (board[j][tempIdx]) {
                temp = board[j][tempIdx];
                board[j][tempIdx] = 0;
                break;
            }
        }
        //printf("%d ", temp);

        // Stack을 Check 하며 Count를 세는 부분
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