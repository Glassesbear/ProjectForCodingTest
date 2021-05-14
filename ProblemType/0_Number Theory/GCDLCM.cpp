#include <stdio.h>
#include <vector>

using namespace std;

// 최대 공약수를 구하는 함수
// 해당 함수를 통해 최대 공약수를 return
// 유클리드 호제법을 이용한 로직
int GCD(int a, int b)
{
	int temp = 0;
	while (b != 0) 
	{
		temp = a % b;
		a = b;
		b = temp;
	}

	return a;
}

int main() {
	int inputA = 0;
	int inputB = 0;

	int resultGCD = 0;
	int resultLCM = 0;

	scanf("%d %d", &inputA, &inputB);


	resultGCD = GCD(inputA, inputB);
	resultLCM = (inputA * inputB) / resultGCD;

	printf("%d, %d", resultGCD, resultLCM);

	return 0;
}