#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int n, a, b, c, kcal,bill;
	cin >> n >> a >> b >> c;
	vector<int>v(n);
	kcal = c;bill = a;
	for (int i = 0; i < n; i++) cin >> v[i];
	sort(v.begin(), v.end(),greater<int>());
	for (int i = 0; i < n; i++) {
		if (c / a < v[i] / b) {//도우 열량 보다 가성비 좋은 토핑 열량 더해줌
			c += v[i];
			a += b;
		}
	}
	cout << c / a << endl;
	return 0;
}
