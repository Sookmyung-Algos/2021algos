#include <iostream>
#include <algorithm>

using namespace std;

int a[100001], b[100001];

int search(int start, int end, int target) {
	if (start > end)
		return -1; //배열 내에서 target값을 찾지 못한 경우 -1 리턴

	int mid = (start + end) / 2; //mid 값 정의

	if (a[mid] == target)
		return mid; //a 배열의 mid 값이 target과 같다면 mid 값 리턴
	else if (a[mid] > target) //a 배열의 mid 값이 target보다 크다면
		return search(start, mid - 1, target); //start부터 mid - 1까지 배열 재탐색
	else //a 배열의 mid 값이 target보다 작다면
		return search(mid + 1, end, target); //mid + 1부터 end까지 배열 재탐색
}

int main() {
	int n, m;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	cin >> m;

	for (int i = 0; i < m; i++) {
		cin >> b[i];
	}

	sort(a, a + n); //오름차순 정렬

	for (int i = 0; i < m; i++) {
		int result = search(0, n - 1, b[i]); //0부터 n-1까지 배열에서 target 값 탐색하여 그 결과를 result에 저장
		if (result != -1)
			cout << 1 << "\n"; //만약 result가 -1이 아니라면 배열 내에 target 값이 있는 것이므로 1 출력
		else
			cout << 0 << "\n"; //만약 result가 -1이라면 배열 내에 target 값이 없는 것이므로 0 출력
	}
}
