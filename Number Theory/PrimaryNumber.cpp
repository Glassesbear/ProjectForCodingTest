#include <stdio.h>




// 소수는 자기 자신과 1을 가지는 수이다
// 예를 들어 2, 3, 5, 7, 11 등이 있다
// 때문에 i 값을 증가시켜 나누어 떨어지지 않는다면, 소수라고 할 수 있다(2 ~ ...)
// 추가적으로 알고리즘의 효율성을 위해 최대로 root(해당수) 까지만 Check 하면 될 것으로 판단됨
// 약수가 있다면, 자기 * 다른수 = 해당수가 되기 때문 (12인 경우, 1, 2, 3, 4, 6, 12가 있고 2인 경우 6이 약수인지 알 수 있다 때문에 rootA 까지만 Check 하면 됨)
bool is_prime(int a) {

	if (a < 2) {
		return false;
	}

	for (int i = 2; i * i <= a; i++) {
		if (a % i == 0){
			return false;
		}
	}

	return true;
}


int main() {

	return 0;
}