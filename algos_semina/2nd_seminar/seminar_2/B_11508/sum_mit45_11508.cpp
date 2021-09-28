#include <iostream>
#include <algorithm>
using namespace std;

int compare(int a, int b) {
	return a > b;
}
int main() {
	int length;
	int cost = 0;

	// 개수 입력
	cin >> length;

	// 동적할당 배열로 입력
	int* array = new int[length]; // 배열 버전 new 연산자 사용

	for (int i = 0; i < length; i++) {
		cin >> array[i];
	}

	// 최대값으로 정렬
	sort(array, array + length, compare);

	// 3,6,9 ... 자리 제외
	for (int i = 0; i < length; i++) {
		if (i % 3 == 2 ) {
			continue;
		}
		cost += array[i];
	}

	cout << cost;

}
