#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int N, result = 0;
int arr[1000001];
vector<int> v;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	v.push_back(arr[0]);// 첫번째 원소는 바로 넣어줌
	for (int i = 1; i < N; i++) { // 2번째 원소부터 살펴봄
		if (v.back() < arr[i]) { // v의 가장 마지막 원소보다 arr[i]값이 크면 
			v.push_back(arr[i]); // v에 삽입함.
		}
		else { // v의 가장 마지막 원소보다 arr[i]값이 작거나 같으면
			auto itr = lower_bound(v.begin(), v.end(), arr[i]);
			// v에서 arr[i]보다 처음으로 큰 원소의 위치를 반환하는 lower_bound()함수를 이용하여
			*itr = arr[i];// 그 위치의 값을 바꿔줌
		}
	}
	cout << v.size() << "\n";// v의 크기가 곧 수열의 길이이므로 v.size()를 출력
	return 0;
}

// 이분탐색으로 분류가 되어 있기 떄문에 처음에는 이분탐색을 활용해서 문제를 풀어봤으나, 백준에서는 시간초과가 발생하여 LIS방식으로 문제를 풀었다
/*
#include <iostream>
#include <algorithm>

using namespace std;
int N, result = 0, idx = 0;
int arr[1000001];

int binary_search(int key)
{
	int s = 0, e = idx + 1;
	while (s <= e) {
		int mid = (s + e) / 2;
		if (arr[mid] > key) {
			e = mid - 1;
		}
		else if (arr[mid] < key) {
			s = mid + 1;
		}
		else {
			return mid;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	cin >> arr[0];
	for (int i = 1; i < N; i++) {
		int a;
		cin >> a;
		if (arr[idx] < a) {
			arr[++idx] = a;
		}
		else {
			arr[binary_search(a)] = a;
		}
	}
	cout << idx + 1 << "\n";
	return 0;
}
*/
