#include <iostream>
#include <vector>
#define MAX 1000001
using namespace std;

struct coord {
	int x;
	int y;
	coord(int x, int y) {
		this->x = x;
		this->y = y;
	}
};

vector<coord> arr, tmp;

void merge(int left, int mid, int right) {
	int left_end = mid - 1,
		tmp_pos = left,
		cnt = right - left + 1;

	while (left <= left_end && mid <= right) {
		if (arr[left].x < arr[mid].x)
			tmp[tmp_pos++] = arr[left++];
		else if (arr[left].x > arr[mid].x)
			tmp[tmp_pos++] = arr[mid++];
		else {
			if (arr[left].y < arr[mid].y)
				tmp[tmp_pos++] = arr[left++];
			else
				tmp[tmp_pos++] = arr[mid++];
		}
		
	}
	while (left <= left_end) tmp[tmp_pos++] = arr[left++];
	while (mid <= right) tmp[tmp_pos++] = arr[mid++];

	for (int i = 0; i < cnt; i++)
		arr[right - i] = tmp[right - i];
}

void merge_sort(int left, int right) {
	int mid;
	if (left < right) {
		mid = (left + right) / 2;
		merge_sort(left, mid);
		merge_sort(mid + 1, right);
		merge(left, mid + 1, right);
	}
}

int main() {
	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(false);

	int n, x, y;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		arr.push_back(coord(x, y));
		tmp.push_back(coord(x, y));
	}

	merge_sort(0, n - 1);

	for (int i = 0; i < n; i++)
		cout << arr[i].x << ' ' << arr[i].y << '\n';

	return 0;
}
