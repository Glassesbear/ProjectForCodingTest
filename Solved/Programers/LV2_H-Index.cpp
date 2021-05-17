#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {

    sort(citations.begin(), citations.end(), greater<int>());

    int refference = 0;
    for(int i = 0; i < citations.size(); i++){
        if(refference >= citations[i]){
            break;
        }
        refference++;
    }
    
    return refference;
}

int main(){
    vector<int> citations = {3, 0, 6, 1, 5};
    int result;
    result = solution(citations); // 3
    return 0;
}