#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// cmp 함수 사용법 check
bool cmp(int a, int b){
    string temp1 = to_string(a) + to_string(b);
    string temp2 = to_string(b) + to_string(a);
    printf("%s : %s\n", temp1.c_str(), temp2.c_str());
    return temp1 > temp2;
}

string solution(vector<int> numbers) {
    
    string answer = "";
    
    sort(numbers.begin(), numbers.end(), cmp);
    
    for(auto it : numbers){
        //printf("%d\n", it);
        answer += to_string(it);
    }
    
    return answer[0] == '0' ? "0" : answer;
}

int main(){
    vector<int> numbers = {6, 10, 2};

    string result;
    result = solution(numbers);
    return 0;
}