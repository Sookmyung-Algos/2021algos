#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int x[1001];
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) 
		cin >> x[i];
	sort(x, x + n);
	int total = 0, time = 0;
	for (int i = 0; i < n; i++) {
		total += x[i];
		time += total;
	}
	cout << time;
}
