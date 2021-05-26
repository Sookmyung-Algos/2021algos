#include <iostream>
#include<algorithm>
using namespace std;

int main() {
	int N, arr[10], cnt=0;
	cin >> N;	// 정렬하고자하는 수 N 입력

	while (N != 0) {
		arr[cnt] = N % 10;
		N /= 10;
		cnt++;
	}	//	N의 각 자리수를 배열 arr의 인덱스0부터 넣음
	sort(arr, arr + cnt, greater<int>());	// 내림차순 정렬
	for (int i = 0; i < cnt; i++) {
		cout << arr[i];
	}	// 정렬한 수 출력
}
