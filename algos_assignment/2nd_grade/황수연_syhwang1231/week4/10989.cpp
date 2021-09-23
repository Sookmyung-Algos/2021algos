//baekjoon 10989 수 정렬하기3

#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
	int n, temp;
	int count[10001] = { 0, };	//개수를 저장할 배열 0으로 초기화

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		count[temp] += 1;   //temp의 개수를 1 증가
	}

	for (int i = 0; i < 10001;i++){
		for (int j = 0; j < count[i]; j++)
			cout << i << "\n";
	}

	return 0;
}
