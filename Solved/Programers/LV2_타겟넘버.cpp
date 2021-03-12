#include <string>
#include <vector>

using namespace std;
int TempCount = 0;

void dfs(vector<int>* numbers, int start, int target, int steps) {

    //int sum = start + numbers[steps + 1];
    if (start == target && steps == numbers->size() - 1) {
        TempCount++;
    }
    else if (steps + 1 < numbers->size()) {
        dfs(numbers, start + numbers->at(steps + 1), target, steps + 1);
        dfs(numbers, start - numbers->at(steps + 1), target, steps + 1);
    }
}

int solution(vector<int> numbers, int target) {
    int answer = 0;

    dfs(&numbers, numbers[0], target, 0);
    //printf("%d", TempCount);
    answer = TempCount;

    return answer;
}

int main() {

    vector<int> temp = { 1,1,1,1,1 };

    solution(temp, 3);

    return 0;
}