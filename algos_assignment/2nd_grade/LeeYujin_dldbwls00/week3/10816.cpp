#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m; // n은 숫자카드의 개수, m은 몇 개 가지고 있는 숫자카드인지 구해야 정수의 수
	vector<int> v; // 숫자카드를 벡터에 넣어 정리

	cin >> n;
	for (int i = 0; i < n; i++) { // 숫자카드 입력
		int card;
		cin >> card;
		v.push_back(card);
	}
	sort(v.begin(), v.end()); // 오름차순 정렬

	cin >> m;
	for (int i = 0; i < m; i++) {
		int key;
		cin >> key;
		// upper_bound: 찾고자하는 값보다 큰 값이 처음으로 나타나는 위치
		// lower_bound: 찾고자하는 값 이상이 처음 나타나는 위치
		cout << upper_bound(v.begin(), v.end(), key) - lower_bound(v.begin(), v.end(), key) << " ";
	}
	return 0;
}
