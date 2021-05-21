//이진검색
#include <iostream>
#include <algorithm>
using namespace std;
int a[1000001], b[1000001];

int search(int start, int end, int target) {
	if (start > end) return -1;
	int mid = (start + end) / 2;

	if (a[mid] == target) return mid;
	else if (a[mid] > target) return search(start, mid - 1, target); //a[mid]가 target보다 크면 start~mid-1 검색
	else return search(mid + 1, end, target); //a[mid]가 target보다 작으면 mid+1~end 검색
}

int main() {
	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	cin >> m;
	for (int i = 0; i < m; i++) cin >> b[i];
	sort(a, a + n); //순서대로 정렬
	for (int i = 0; i < m; i++) {
		int result = search(0, n - 1, b[i]);
		if (result != -1)
			cout << 1 << "\n"; //값이 존재하면 1 
		else
			cout << 0 << "\n"; //아니면 0
	
	}
}
