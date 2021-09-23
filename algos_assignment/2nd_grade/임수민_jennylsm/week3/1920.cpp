#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	int t;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++){
		cin >> arr[i];  //벡터에 n개짜리 배열을 입력받는다
	}

	cin >> m;

	sort(arr.begin(), arr.end()); //배열 정렬

	for (int i = 0; i < m; i++){
		cin >> t;
		cout << binary_search(arr.begin(), arr.end(), t) << '\n';  //이진탐색을 통해 배열에 있는지 탐색
	}

	return 0;
}
