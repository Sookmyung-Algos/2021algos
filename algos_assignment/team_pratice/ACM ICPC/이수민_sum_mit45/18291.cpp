#include<iostream>
using namespace std;
typedef long long ll;
ll mmax = 1e9 + 7;

int pow(int a, int b) {
	if (b == 0)
		return 1;
	else if (b % 2 == 0) {
		ll mul = pow(2, b / 2);
		return mul * mul % mmax;
	}
	else {
		ll mul = pow(2, b / 2);
		ll temp = mul * mul % mmax;
		return a * temp % mmax;
	}
}

int main() {
	ios::sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);
	int t;
	cin >> t;
	while (t--)	{
		int n;
		cin >> n;
		if (n == 1)
			cout << 1 << "\n";
		else
			cout << pow(2, n - 2) << "\n";
	}
	return 0;
}
