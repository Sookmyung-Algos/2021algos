#include <iostream>
using namespace std;

int a, b, c;
int p, n, zero;

void calc(int x, int y) {
	int result = a * x + b * y + c;

	if (result > 0) p++;
	else if (result == 0) zero++;
	else n++;
}

int main() {
	int x[2], y[2];

	cin >> a >> b >> c;
	cin >> x[0] >> x[1] >> y[0] >> y[1];

	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
			calc(x[i], y[j]);
	
	if (p + zero == 4 || n + zero == 4) cout << "Lucky";
	else cout << "Poor";
}
