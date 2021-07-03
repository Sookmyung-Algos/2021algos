#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n,a,b,c,topping,temp;
vector<int>d(10001);


int main() {
	cin >> n;
	cin >> a >> b;
	cin >> c;
	for (int i = 0; i < n; i++)
		cin >> d[i];

	sort(d.begin(), d.end());
	reverse(d.begin(), d.end());


	for (int i = 0; i < n; ++i) {
		if (c / a < d[i] / b) {
			c += d[i];
			a += b;
		}
	}
	cout << c / a;

	return 0;
}
