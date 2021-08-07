#include <iostream>

using namespace std;

int main()
{
	float a, b, c;
	cin >> a >> b >> c;

	float x1, x2, y1, y2;
	cin >> x1 >> x2 >> y1 >> y2;

	float k1 = a*x1 + b*y1 + c;
	float k2 = a*x2 + b*y2 + c;
	float k3 = a*x1 + b*y2 + c;
	float k4 = a*x2 + b*y1 + c;

	if (k1 == 0 || k2 == 0) {
		cout << "Lucky";
	}
	else if ((k1 < 0 && k2>0) || (k1 > 0 && k2 < 0)) {
		cout << "Poor";
	}
	else if ((k3>0 && k4<0) || (k3<0 && k4>0)) {
		cout << "Poor";
	}
	else cout << "Lucky";

}
