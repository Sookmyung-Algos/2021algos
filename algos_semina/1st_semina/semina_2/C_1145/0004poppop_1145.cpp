#include <iostream>
using namespace std;

int main() {
	int num[5];
	for (int i = 0; i < 5; i++)
		cin >> num[i]; // 자연수 5개 입력받기

	for (int j = 1;; j++) { // 정수j 1씩 증가
		int count = 0;
		for (int i = 0; i < 5; i++) {
			if (j % num[i] == 0) {
				count++;
			} // j가 num 배열요소의 배수일때 count 증가
		}
		if (count >= 3) { // count가 3이상일 때
			cout << j; // 대부분의 배수가 되어 출력
			break;
		}
	}
	return 0;
}
