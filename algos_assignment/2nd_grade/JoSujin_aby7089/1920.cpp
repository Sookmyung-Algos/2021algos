#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <vector>
using namespace std;
vector<pair<int, int>> v;
int n, m;
int a[100001];

void binsearch(int key) {
	int s = 0, e = n - 1, mid;
	while (s <= e) {
		mid = (s + e) / 2;  //s와 e가 계속 바뀌므로 while문 밖에서 정의x
		if (key < a[mid])
			e = mid - 1;
		else if (key > a[mid])
			s = mid + 1;
		else {
			cout << "1" << "\n";
			return;
		}
	}
	cout << "0" << "\n";
	return;
}

int main() {
	iostream::sync_with_stdio(0);
	cin.tie(0);	
	int b;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n);
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> b;
		binsearch(b);
	}
}
