#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int main() {
	int i, j, n;
	int arr_max[3] = { 0 }, arr_min[3] = { 0 };
	int tmp_max[3] = { 0 }, tmp_min[3] = { 0 };
	cin >> n;

	for (i = 0; i < n; i++) {
		for (j = 0; j < 3; j++) {
			cin >> tmp_max[j];
			tmp_min[j] = tmp_max[j];
			tmp_max[j] += max(arr_max[1], (j == 1) ? max(arr_max[0], arr_max[2]) : arr_max[j]);
			tmp_min[j] += min(arr_min[1], (j == 1) ? min(arr_min[0], arr_min[2]) : arr_min[j]);
		}
		memcpy(arr_max, tmp_max, sizeof(int) * 3);
		memcpy(arr_min, tmp_min, sizeof(int) * 3);
	}
	sort(arr_max, arr_max + 3);
	sort(arr_min, arr_min + 3);
	cout << arr_max[2] << " " << arr_min[0] << '\n';
	return 0;
}
