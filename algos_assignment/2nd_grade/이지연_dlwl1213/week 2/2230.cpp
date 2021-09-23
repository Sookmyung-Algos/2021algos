#include <iostream>
#include <algorithm>

using namespace std;
long long A[100001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int num;
	long long max;
	cin >> num >> max;

	for (int i = 0; i < num; i++)
		cin >> A[i];
	sort(A, A + num);
	int r = 0, l = 0;
	long long dif = 0, result = 2000000001;
	while (l <= r && r < num) {
		if (dif >= max) {
			result = min(result, dif);
			if (l == r) {
				r++;
				if (r == num)
					break;
				dif = A[r] - A[l];
			}
			else {
				l++;
				dif = A[r] - A[l];
			}
		}
		else {
			r++;
			if (r == num)
				break;
			dif = A[r] - A[l];
		}
	}
	cout << result;
	return 0;
}
