#include <iostream>
using namespace std;

int N, T;
long long d = 1000000007;
int find_route(int a, int b)
{
	long long multi;
	if (b == 0) return 1;
	else if (b % 2 == 1) {
		multi = find_route(2, b / 2);
		multi = multi * multi % d;
		return a * multi % d;
	}
	else {
		multi = find_route(2, b / 2);
		return multi * multi % d;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> T;
	while (T--) {
		cin >> N;
		int result;
		if (N == 1) result = 1;
		else result = find_route(2, N - 2);
		cout << result << "\n";
	}
	return 0;
}
