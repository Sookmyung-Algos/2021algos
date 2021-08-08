#include <iostream>
using namespace std;

int check(int x[], int y[], int a, int b, int c)
{
	int lmin, lmax, pmin, pmax;
	// 통과하는 경우의 최대,최소와 통과하지 않는 경우의 최대최소 비교 
	lmin = min(-1 * a * x[0] - c, -1 * a * x[1] - c);
	lmax = max(-1 * a * x[0] - c, -1 * a * x[1] - c);

	pmin = min(b * y[0], b * y[1]);
	pmax = max(b * y[0], b * y[1]);

	if (lmin >= pmax || lmax <= pmin)
		return 1; // 통과하지 않는 경우
	else return 0;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int a, b, c;
	int x[2], y[2];
	cin >> a >> b >> c;
	cin >> x[0] >> x[1] >> y[0] >> y[1];

	if (check(x, y, a, b, c)) cout << "Lucky\n";
	else cout << "Poor\n";

	return 0;
}
