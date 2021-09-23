#include <iostream>
#include <vector>
using namespace std;

class Point {
public:
	int x;
	int y;
	Point(int x, int y) {
		this->x = x;
		this->y = y;
	}
};
vector<Point> temp;
vector<Point> arr;

void merge(int left, int mid, int right) {
	int left_end, num_elements, tmp_pos;
	left_end = mid - 1;
	tmp_pos = left;
	num_elements = right - left + 1;
	while (left <= left_end && mid <= right) {
		if (arr[left].x < arr[mid].x)
			temp[tmp_pos++] = arr[left++];
		else if (arr[left].x > arr[mid].x)
			temp[tmp_pos++] = arr[mid++];
		else {
			if (arr[left].y < arr[mid].y)
				temp[tmp_pos++] = arr[left++];
			else
				temp[tmp_pos++] = arr[mid++];
		}
	}
	while(left<=left_end)
		temp[tmp_pos++] = arr[left++];
	while(mid<=right)
		temp[tmp_pos++] = arr[mid++];
	for (int i = 0; i < num_elements; i++) {
		arr[right] = temp[right];
		right -= 1;
	}
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
	int n, x, y;
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		arr.push_back(Point(x, y));
		temp.push_back(Point(x, y));
	}
	merge_sort(0, n - 1);
	
	for (int i = 0; i < n; i++)
		cout << arr[i].x << " " << arr[i].y << "\n";
}
