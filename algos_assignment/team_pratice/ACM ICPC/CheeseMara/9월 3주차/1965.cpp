#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int max_box[1001];
int maximum = 0;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;
	vector<int> v(N);

	for (auto& x : v) cin >> x;
	for (int i = 0; i < N; i++) {
		max_box[i] = 0;
		for (int j = 0; j < i; j++) {
			if (v[i] > v[j] && max_box[i] < max_box[j] + 1) max_box[i] = max_box[j] + 1;
		}
	}
	cout << *max_element(max_box, max_box + N + 1) + 1;
}
