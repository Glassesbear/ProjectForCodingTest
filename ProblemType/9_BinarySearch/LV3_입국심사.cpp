#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    
    sort(times.begin(), times.end());    
    
    // 시간을 최대 최소로 뒀을때,
    // 최소가 되는 경우, 1분에 1명일때,
    long long start = 1;
    // 오래 걸리는 사람에게 모든 사람이 대기할 때
    long long end = (long long)n * times.back();
    //printf("%d\n", end);
    long long mid;
    long long passPeople = 0;
    
    while(start <= end){
        
        mid = (start + end) / 2;
        
        // 평균시간 / 걸리는 시간이 1인 경우면, 한 사람이 지나갔다고 볼 수 있다
        passPeople = 0;
        for(int i = 0; i < times.size(); i++){
            passPeople += mid / times[i];
            //printf("%d : %d : %d : mid(%d)\n", i, passPeople, mid / times[i], mid);
        }
                
        if(passPeople < n){
            start = mid + 1;
        }
        
        else{
            if(mid <= end)
                answer = mid;
            end = mid - 1;
        }
    }
    
    return answer;
}

int main(){
    vector<int> times = {7, 10};

    int result;
    result = solution(6, times);
    return 0;
}