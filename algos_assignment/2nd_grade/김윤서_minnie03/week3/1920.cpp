#1920 수찾기
#include <iostream>
#include <algorithm>
using namespace std;

int a[100001],b[100001];

int search(int start, int end, int target) {
	if (start > end)return -1; //target을 찾지 못한 경우 -1 리턴
	int mid = (start + end) / 2;

	if (a[mid] == target) return mid; //target 값을 찾으면 mid 값 리턴
	else if (a[mid] > target) return search(start, mid - 1, target); //target값이 a[mid]보다 작으면 start~mid-1의 범위로 재귀적으로 search 함수 호출
	else return search(mid + 1, end, target); //target이 a[mid]보다 크면 재귀적으로 mid+1~end 범위로 search 함수 호출
}

int main() {
	int n, m;
	cin >> n; //배열 a의 원소의 개수 n 입력
	for (int i = 0; i < n; i++) { //n개의 a 원소 값 입력
		cin >> a[i];
	}
	cin >> m; //찾을 정수의 개수 m 입력
	for (int i = 0; i < m; i++) { //m개의 b 원소 값 입력
		cin >> b[i];
	}
	sort(a, a + n); //a의 원소를 오름차순 정렬
	for (int i = 0; i < m; i++) {
		int result = search(0, n - 1, b[i]); //b[i]가 배열 a의 원소라면 그 위치를 반환하여 result에 대입, 원소가 아니라면 -1을 반환하여 result에 대입
		if (result != -1) //원소가 맞다면 1 출력
			cout << 1 << "\n";
		else //원소가 아니라면 0 출력
			cout << 0 << "\n";
	}
}
