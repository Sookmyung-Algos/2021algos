#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(int a, int b) {
	return a > b;
}

int main() {
	int n, a, b, c, d[101];
	cin >> n;
	cin >> a >> b;
	cin >> c;
	for (int i = 0; i < n; i++) cin >> d[i];
	sort(d, d + n, cmp);

	vector <int> pizza;

	pizza.push_back(c / a);
	
	for (int i = n-1; i >=0; i--) {
		int cal = c;
		for (int j = 0; j <= i;j++) {
			cal += d[j];
		}
		int p = a + b*(i + 1);
		pizza.push_back(cal / p);
	}
	sort(pizza.begin(), pizza.end(), cmp);
	cout << pizza[0];
}
