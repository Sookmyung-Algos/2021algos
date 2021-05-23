#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	int n;
	cin >> n;

	vector <int> v;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		v.push_back(num); //벡터에 자연수 푸쉬
	}
	sort(v.begin(), v.end()); //정렬

	int mid = (n - 1) / 2; //정렬 된 벡터에서는 중간값이 대표 자연수임

	cout << v[mid] << '\n'; //출력
}
