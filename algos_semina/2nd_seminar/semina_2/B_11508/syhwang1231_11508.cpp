#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int cmp(int a, int b) {  // 내림차순 정렬
	return a > b;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	vector <int> dairy;

	int n;  // 유제품의 수
	int c;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &c);
		dairy.push_back(c);
	}
	
	sort(dairy.begin(), dairy.end(), cmp);

	int sum = 0;
	for (int i = 0; i < n; i++) {
		if (i % 3 != 2)  // 고른 3개 제품 중 가장 싼 제품은 인덱스를 3으로 나눈 나머지가 2
			sum += dairy[i];
	}
	printf("%d", sum);
	return 0;
}
