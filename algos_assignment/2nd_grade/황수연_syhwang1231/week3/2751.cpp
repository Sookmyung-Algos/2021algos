//baekjoon 2751 수 정렬하기2 (퀵 정렬->시간초과 => sort()함수 사용함)

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>

using namespace std;

int num[1000000];
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	scanf("%d", &n);	//수의 개수 입력

	for (int i = 0; i < n; i++) {	//n개의 수 입력받기
		scanf("%d", &num[i]);
	}

	sort(num, num + n);

	for (int i = 0; i < n; i++) {
		printf("%d\n", num[i]);
	}

	return 0;
}
