#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = s.length();

    // �ڸ� ���ڸ� ���� vector
    vector<string> v;

    // ���� index
    int startIdx = 0;

    // �ڸ� ���ڼ�
    int dividedNum = 0;

    string temp = "";
    string tempString = "";
    int count = 0;
    for (int i = 1; i < s.length(); i++) {
        startIdx = 0;
        //printf("=================%d : %d : %d\n", i, s.length(), dividedNum % i);
        if (s.length() % i == 0) {
            dividedNum = (s.length() / i);
        }
        else
            dividedNum = (s.length() / i) + 1;

        // ���� �߶� vector�� ����
        for (int j = 0; j < dividedNum; j++) {
            temp = s.substr(startIdx, i);
            v.push_back(temp);

            //printf("%d : %d\n", startIdx, i);
            //printf("%d : %d : %s\n", j, dividedNum, temp.c_str());
            startIdx = startIdx + i;
        }

        // vector�� ��ȸ�ϸ� �����Ͽ� ���ο� ���ڿ��� ����
        tempString = "";
        for (int k = 0; k < v.size(); k++) {
            count = 0;
            //printf("%d : %s\n", k, v[k].c_str());
            for (int l = k + 1; l < v.size(); l++) {
                //printf("%d : %s : %s\n", count, v[k].c_str(), v[l].c_str());
                if (v[k] == v[l]) {
                    count++;
                }
                else {
                    break;
                }
            }

            if (count) {
                tempString += to_string(count + 1) + v[k];
            }
            else {
                tempString += v[k];
            }
            //printf("%s\n", tempString.c_str());
            k = k + count;
        }
        v.clear();

        if (answer > tempString.length()) {
            answer = tempString.length();
        }
    }


    return answer;
}

int main() {

    string temp = "aabbaccc";
    printf("%d\n", solution(temp));//7

    return 0;
}