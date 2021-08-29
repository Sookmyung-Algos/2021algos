#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int arr[100001];

int binarySearch(int s, int e, int key)
{
	while (s <= e) {
		int mid = (s + e) / 2;
		if (arr[mid] > key) e = mid - 1;
		else if (arr[mid] < key) s = mid + 1;
		else return 1;
	}
	return 0;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + N);

	cin >> M;
	for (int i = 0; i < M; i++) {
		int x; cin >> x;
		cout << binarySearch(0, N - 1, x) << "\n";
	}
	return 0;
}
