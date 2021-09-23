#include <iostream>
#include <vector>
using namespace std;

class point { // x, y 순서쌍
public:
	int x, y;
	point(int x, int y) {
		this->x = x;
		this->y = y;
	}
};
vector<point> temp; // 순서쌍 벡터
vector<point> arr; // 순서쌍 벡터

void merge(int left, int mid, int right);
void mergesort(int left, int right);

int main() {
	int n, x, y;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		arr.push_back(point(x, y));
		temp.push_back(point(x, y));
	}
	mergesort(0, n - 1);
	for (int i = 0; i < n; i++)	cout << arr[i].x << " " << arr[i].y << '\n';
	return 0;
}

void merge(int left, int mid, int right) {
	int leftEnd, numElements, tmpPos;
	leftEnd = mid - 1;
	tmpPos = left;
	numElements = right - left + 1; // left ~ right 개수
	
	while (left <= leftEnd && mid <= right) {
		if (arr[left].x < arr[mid].x)	temp[tmpPos++] = arr[left++];
		else if (arr[left].x > arr[mid].x)	temp[tmpPos++] = arr[mid++];
		else {
			if (arr[left].y < arr[mid].y)	temp[tmpPos++] = arr[left++];
			else temp[tmpPos++] = arr[mid++];
		}
	}
	while (left <= leftEnd)	temp[tmpPos++] = arr[left++];
	while (mid <= right)	temp[tmpPos++] = arr[mid++];
	for (int i = 0; i < numElements; i++) {
		arr[right] = temp[right];
		right -= 1;
	}
}

void mergesort(int left, int right) {
	int mid;
	if (left < right) {
		mid = (left + right) / 2;
		mergesort(left, mid); // left segment
		mergesort(mid + 1, right); // right segment
		merge(left, mid + 1, right); // merge
	}
}
