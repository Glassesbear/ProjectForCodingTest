#include <vector>
#include <string>

using namespace std;

class Solution {
public:

    // ��� �κп� ���� ó��
    // ������ ���� ��� 1�� ���� ���ؼ��� ó��
    // �ٸ� ��� �� ���� ���� ȭ��ǥ ó��
    string makeString(int nStart, int nEnd) {
        if (nStart == nEnd) {
            return to_string(nStart);
        }
        return to_string(nStart) + "->" + to_string(nEnd);
    }


    // ���� ���� ���������� ó���ϸ� �信 ���� Ȯ���� �� �ִ�.
    // ������ -> nums[0]
    // nums[max] -> �ִ밪�� ����
    // ���������� ó���� �� �ִ� ������ ������

    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> answer;
        int len = nums.size();

        //�ٷ� ����Ǵ� ����
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

        // ù��° ó�� (lower -> nums[0]) 
        if (lower < nums[0]) {
            answer.push_back(makeString(lower, nums[0] - 1));
        }

        // nums[0] -> nums[n] ���� ���������� ó��
        for (int i = 1; i < len; i++) {
            if (nums[i] > nums[i - 1] && nums[i - 1] != nums[i] - 1) {
                answer.push_back(makeString(nums[i - 1] + 1, nums[i] - 1));
            }
        }

        // ������ �κп� ���� ó��
        if (upper > nums[len - 1]) {
            answer.push_back(makeString(nums[len - 1] + 1, upper));
        }


        return answer;
    }
};