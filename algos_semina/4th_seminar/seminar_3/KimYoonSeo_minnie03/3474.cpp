#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int main() {

	int t, n[100001] = { 0, }, result[100001] = { 0, };
	scanf("%d", &t); //t를 입력받음

	int k = 0; //k는 테스트 케이스의 번호
	while (k < t) { //t개의 테스트 케이스 동안
		scanf("%d", n + k); //각 테스트마다 n을 입력

		int five = 0;

		for (int i = 5; i <= n[k]; i *= 5)
			five += (n[k] / i); //5의 배수만큼 n[k]로 나눈 값을 five에 더함
		//소인수분해 했을 때에 2와 5의 개수 중 작은 것이 결국 10의 몇배수인지 알 수 있지만
		//2와 5 중 결국 5의 개수가 더 적은것이 분명하므로 5의 배수만 탐색

		result[k] = five; //최종 five의 개수를 result에 저장

		printf("%d\n", result[k]); //최종 result 출력

		k++; //테스트 케이스 다음으로 넘어감 

	}

	return 0;
}
