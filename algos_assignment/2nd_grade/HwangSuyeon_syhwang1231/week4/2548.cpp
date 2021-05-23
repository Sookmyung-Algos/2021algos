//baekjoon 2548 대표 자연수

#include <iostream>
#include <algorithm>

using namespace std;

int num[20000];

int main(void) {
	int n;
	//int num[20000];
	cin >> n;	//자연수의 개수 n 입력

	for (int i = 0; i < n; i++)
		cin >> num[i];

	sort(num, num + n);		//정렬

	cout << num[(n - 1) / 2];

	return 0;
}
