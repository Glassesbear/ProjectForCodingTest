#include <string>
#include <vector>
#include <queue>
#include <stdio.h>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;

    priority_queue<int, vector<int>, greater<int>> tempQ;
    
    for (int i =0; i < scoville.size(); i++){
        tempQ.push(scoville[i]);
        //printf("%d\n", scoville[i]);
    }
    
    bool tempFlag = false;
    int first = 0;
    int second = 0;
    //printf("%d\n", tempQ.top());
    while(tempQ.size() > 1){
        // 살사 선정
        first = tempQ.top();
        tempQ.pop();
        second = tempQ.top();
        tempQ.pop();
        
        // 횟수 추가
        answer++;
        
        tempQ.push(first + (2*second));
        //printf("%d\n", tempQ.top());
        
        // 성공 유/무를 check 하기 위한 flag 추가
        if(tempQ.top() >= K){
            tempFlag = true;
            break;
        }
    }
    
    if(tempFlag == false)
        answer = -1;
    
    return answer;
}

int main() {
    vector<int> scoville = {1, 2, 3, 9, 10, 12};
    printf("%d\n", solution(scoville, 7));//2
    return 0;
}