#include <iostream>
using namespace std;

int main() {
	int a, b, c;
	int x1, x2, y1, y2;

	cin >> a >> b >> c;
	cin >> x1 >> x2 >> y1 >> y2;

	int plma[4];
	plma[0] = a * x1 + b * y1 + c;
	plma[1] = a * x2 + b * y1 + c;
	plma[2] = a * x1 + b * y2 + c;
	plma[3] = a * x2 + b * y2 + c;

	int result[2] = { 0, };
	
	for (auto i : plma){
		if (i >= 0) result[0]++;
		if (i <= 0) result[1]++;
	}

	if (result[0] == 4 || result[1] == 4) cout << "Lucky";
	else cout << "Poor";
	return 0;
}
