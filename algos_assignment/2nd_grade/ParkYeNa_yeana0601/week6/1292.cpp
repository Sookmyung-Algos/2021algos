#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int A, B;
int arr[1001];

int main() {
	ios::sync_with_stdio;
	cin.tie(0); cout.tie(0);
	cin >> A >> B;
	int idx = 0;
	for (int i = 0; i < 1000; i++) {
		for (int j = 0; j < i && idx < 1000; j++) arr[idx++] = i;
	}
	int ans = 0;
	for (int i = A - 1; i <= B - 1; i++) {
		ans += arr[i];
	}

	cout << ans;
}
