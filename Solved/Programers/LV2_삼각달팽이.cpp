#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n) {

    // 2���� �迭�� �����غ���
    // �椷���� �Ʒ�->��->�� ������ �ݺ��Ѵٸ� ���� �� ���� ������ �Ǵ�
    vector<int> answer;
    int temp[1001][1001] = { 0, };
    int state = 0;
    //state == 0, �Ʒ�
    //state == 1, ��
    //state == 2, ��

    int x = 0;
    int y = 0;
    int number = 1;
    int count = 0;
    int rotate = n;

    while (rotate) {
        count = 0;
        if (state == 0) {
            for (int i = 0; i < rotate; i++) {
                temp[y + i][x] = number++;
                count++;
            }
            y += count - 1;
            x++;
            state = 1;
        }
        else if (state == 1) {
            for (int i = 0; i < rotate; i++) {
                temp[y][x + i] = number++;
                count++;
            }
            x += count - 2;
            y -= 1;
            state = 2;
        }
        else if (state == 2) {
            for (int i = 0; i < rotate; i++) {
                temp[y - i][x - i] = number++;
                count++;
            }
            x = x - count + 1;
            y = y - count + 2;
            state = 0;
        }

        // ǥ ǥ��
        //for(int i = 0; i < 10; i++){
            //for(int j = 0; j < 10 ; j++){
                //printf("%d ", temp[i][j]);
            //}
            //printf("\n");
        //}
        //printf("\n");
        rotate--;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            //printf("%d ", temp[i][j]);
            if (temp[i][j] != 0) {
                answer.push_back(temp[i][j]);
            }
        }
    }

    return answer;
}

int main() {
    vector<int> result;
    result = solution(4);

    for (int i = 0; i < result.size(); i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

    return 0;
}