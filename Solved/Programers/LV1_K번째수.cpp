#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    int start = 0;
    int end = 0;
    int k = 0;
    for (int i =0; i<commands.size(); i++){
        start = commands[i][0] - 1;
        end = commands[i][1] - 1;
        k = commands[i][2] - 1;
        
        vector<int> temp;
        for (int j = start; j <= end; j++){
            temp.push_back(array[j]);
        }
        
        sort(temp.begin(), temp.end());
        
        answer.push_back(temp[k]);
    }
    
    
    return answer;
}

int main(){
    vector<int> array = {1, 5, 2, 6, 3, 7, 4};
    vector<vector<int>> commands = {{2,5,3},{4,4,1},{1,7,3}}
    
    vector<int> result;
    result = solution(array, commands);//5,6,3
    return 0;l
}