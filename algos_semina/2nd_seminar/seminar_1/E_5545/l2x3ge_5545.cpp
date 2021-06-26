#include<iostream>
#include<algorithm>
using namespace std;
int main() {
	int n, a, b, c, cal = 0, price = 0;
	int d[10001];
	cin >> n >> a >> b >> c;
	for (int i = 0;i < n;i++) {
		cin >> d[i];
	}
	sort(d, d + n, greater<>());
	cal += c;
	price += a;
	int result = cal / price;
	for (int i = 0;i < n;i++) {
		cal += d[i];
		price += b;
		if (result > cal / price)
			break;
		result = cal / price;
	}

	cout << result;
	return 0;
}
