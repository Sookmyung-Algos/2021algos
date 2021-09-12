#include <iostream>

using namespace std;

int a, b, c, d;

int GCD(int a, int b) {
	while (b != 0) {
		int r = a % b;
		a = b;
		b = r;
	}
	return a;
}

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> a >> b >> c >> d;
	int e, f;
	e = (a * d + b * c);
	f = b * d;
	int g = GCD(e, f);
	cout << e / g << " " << f / g;
    
	return 0;
}
