#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    
    sort(times.begin(), times.end());    
    
    // �ð��� �ִ� �ּҷ� ������,
    // �ּҰ� �Ǵ� ���, 1�п� 1���϶�,
    long long start = 1;
    // ���� �ɸ��� ������� ��� ����� ����� ��
    long long end = (long long)n * times.back();
    //printf("%d\n", end);
    long long mid;
    long long passPeople = 0;
    
    while(start <= end){
        
        mid = (start + end) / 2;
        
        // ��սð� / �ɸ��� �ð��� 1�� ����, �� ����� �������ٰ� �� �� �ִ�
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