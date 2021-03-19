#include <vector>
#include <string>

using namespace std;

class Solution {
public:

    // 출력 부분에 대한 처리
    // 동일한 값일 경우 1개 값에 대해서만 처리
    // 다를 경우 두 값에 대한 화살표 처리
    string makeString(int nStart, int nEnd) {
        if (nStart == nEnd) {
            return to_string(nStart);
        }
        return to_string(nStart) + "->" + to_string(nEnd);
    }


    // 값에 대한 순차적으로 처리하면 답에 대해 확인할 수 있다.
    // 최저값 -> nums[0]
    // nums[max] -> 최대값에 대해
    // 순차적으로 처리할 수 있는 생각을 가지자

    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> answer;
        int len = nums.size();

        //바로 종료되는 조건
        if (nums.size() == 0) {
            if (lower == upper) {
                answer.push_back(to_string(lower));
            }

            else {
                string temp;
                temp = to_string(lower) + "->" + to_string(upper);
                //printf("result : %s\n", temp.c_str());
                answer.push_back(temp);

            }
            return answer;
        }

        // 첫번째 처리 (lower -> nums[0]) 
        if (lower < nums[0]) {
            answer.push_back(makeString(lower, nums[0] - 1));
        }

        // nums[0] -> nums[n] 까지 순차적으로 처리
        for (int i = 1; i < len; i++) {
            if (nums[i] > nums[i - 1] && nums[i - 1] != nums[i] - 1) {
                answer.push_back(makeString(nums[i - 1] + 1, nums[i] - 1));
            }
        }

        // 마지막 부분에 대해 처리
        if (upper > nums[len - 1]) {
            answer.push_back(makeString(nums[len - 1] + 1, upper));
        }


        return answer;
    }
};