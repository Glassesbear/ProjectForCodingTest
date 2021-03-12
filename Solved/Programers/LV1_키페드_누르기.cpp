#include <string>
#include <vector>
#include <stdio.h>
#include <cstdlib>

// ��ǥ ���� �ٷ� ����ϱ� ���� define
#define isX(input) input%3
#define isY(input) input/3

using namespace std;

// �ѹ��е��� ��ǥ���� ����ϱ� ���� �迭
char numberPad[12] = { '1','2','3','4','5','6','7','8','9','*','0','#' };

// ���� ������ ������ ����
char rThumb = '#';
char lThumb = '*';

// 2,5,8,0�� ���� ������ �޼� �Ǻ��ϱ� ���� �ڵ�
string resultHand(bool handState, int number) {

    int tempNumX = 0;
    int tempNumY = 0;

    int lThumbX = 0;
    int lThumbY = 0;

    int rThumbX = 0;
    int rThumbY = 0;

    // ��ǥ��� ���� ����, ������ �޼� ��ǥ
    for (int i = 0; i < 12; i++) {
        if (numberPad[i] == (number + '0')) {
            tempNumX = isX(i);
            tempNumY = isY(i);
        }

        if (lThumb == numberPad[i]) {
            lThumbX = isX(i);
            lThumbY = isY(i);
        }

        if (rThumb == numberPad[i]) {
            rThumbX = isX(i);
            rThumbY = isY(i);
        }
    }

    // �� ��ġ�� ���� ��ǥ ����Ͽ� �޼� �������� ������
    int diffR = 0;
    int diffL = 0;

    diffL = abs(tempNumX - lThumbX) + abs(tempNumY - lThumbY);
    diffR = abs(tempNumX - rThumbX) + abs(tempNumY - rThumbY);

    string result = "";
    if (diffL == diffR) {
        if (handState) {
            result = "R";
            rThumb = (char)number + '0';
        }
        else {
            result = "L";
            lThumb = (char)number + '0';
        }
    }
    else if (diffL < diffR) {
        result = "L";
        lThumb = (char)number + '0';
    }
    else {
        result = "R";
        rThumb = (char)number + '0';
    }

    return result;
}

string solution(vector<int> numbers, string hand) {

    // �� ���� ���¸� Check
    bool handState = false;
    if (hand.compare("right") == 0) {
        handState = true;
    }

    string answer = "";
    for (int i = 0; i < numbers.size(); i++) {

        if (numbers[i] == 1 || numbers[i] == 4 || numbers[i] == 7) {
            answer += "L";
            lThumb = (char)numbers[i] + '0';
        }

        else if (numbers[i] == 3 || numbers[i] == 6 || numbers[i] == 9) {
            answer += "R";
            rThumb = (char)numbers[i] + '0';
        }

        else {
            answer += resultHand(handState, numbers[i]);
        }
        //printf("left = %c :right = %c\n", lThumb, rThumb);
    }

    //printf("%s", answer.c_str());
    return answer;
}

int main() {

    vector<int> numbers = { 1, 3, 4, 5, 8, 2, 1, 4, 5, 9, 5 };
    string hand = "right";
    solution(numbers, hand);

    return 0;
}