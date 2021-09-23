#include <iostream>
#include <algorithm>
using namespace std;

int binarysearch(int, int, int);
int a[100001], b[100001];

int main() {
	int n, m; //n은 정수의 수, m은 있는지 찾을 정수의 수

	cin >> n;
	for (int i = 0; i < n; i++)	cin >> a[i];
	sort(a, a + n); // a 원소 오름차순 정렬

	cin >> m;
	for (int i = 0; i < m; i++)	cin >> b[i];

	for (int i = 0; i < m; i++) {
		int result = binarysearch(0, n - 1, b[i]);
		if (result != -1)	cout << 1 << "\n"; // 있는 경우
		else cout << 0 << '\n'; // 없는 경우
	}

	return 0;
}

int binarysearch(int start, int end, int target) {
	int mid = (start + end) / 2;

	if (start > end)	return -1; // target을 찾지 못한 경우
	if (a[mid] == target)	return mid; // target을 찾은 경우
	else if (a[mid] > target)	return binarysearch(start, mid - 1, target); // mid 왼쪽에서 재귀
	else return binarysearch(mid + 1, end, target); // mid 오른쪽에서 재귀
}
