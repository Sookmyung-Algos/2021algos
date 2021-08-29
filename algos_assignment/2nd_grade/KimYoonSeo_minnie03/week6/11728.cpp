#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int n, m;
int a[1000001], b[1000001], result[2000002];

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) { //a배열 원소 입력
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < m; i++) { //b배열 원소 입력
		scanf("%d", &b[i]);
	}
	int i = 0, j = 0, k = 0; //a배열,b배열,result배열 인덱스
	
	while (i < n && j < m) { //a, b배열 둘중 하나라도 모든 원소를 result에 저장하면 while문 빠져나감
		if (a[i] < b[j]) { //a의 원소가 더 작다면
			result[k++] = a[i++]; //a원소 result에 입력
		}
		else { //b의 원소가 더 작다면
			result[k++] = b[j++]; //b원소 result에 입력
		}
	}
	
	//a나 b배열의 원소 중 result에 들어가지 않은 원소만 result에 그대로 저장
	while (i < n) result[k++] = a[i++];
	while (j < m) result[k++] = b[j++];

	for (int p= 0 ; p < n + m; p++) {
		printf("%d ", result[p]);
	}
	return 0;
}
