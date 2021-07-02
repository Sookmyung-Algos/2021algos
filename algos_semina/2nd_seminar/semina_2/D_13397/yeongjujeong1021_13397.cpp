#include <iostream>
#define MAX 5001
using namespace std;

int arr[MAX];

int n, m, ans = 10001;

void bs(int left, int right) {
	if (left <= right) {
		int mid = (left + right) / 2;
		int min_num = 10001, max_num = 0, tmp = 0, cnt = 1, max_tmp = 0;

		for (int i = 0; i < n; i++) {
			min_num = min(min_num, arr[i]);
			max_num = max(max_num, arr[i]);

			tmp = max_num - min_num;
			if (tmp > mid) {
				cnt++;
				min_num = arr[i];
				max_num = arr[i];
			}
			else
				max_tmp = max(max_tmp, tmp);
		}
		if (cnt <= m) {
			ans = min(ans, max_tmp);
			bs(left, mid - 1);
		}
		else {
			bs(mid + 1, right);
		}

	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(); cout.tie();

	int right = 0;

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		right = max(right, arr[i]);
	}

	bs(0, right);

	cout << ans << '\n';


	return 0;
}
