#include <iostream>
#include <algorithm>
using namespace std;

bool compare(int a, int b) {
	return a > b;
}
int main() {
	int n;
	int cost = 0;
	cin >> n;
	int* c = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> c[i];
	}
	sort(c, c + n, compare);
	for (int j = 0; j < n; j++) {
		if (j % 3 == 2) {
			continue;
		}
		cost += c[j];
	}
	cout << cost;
}
