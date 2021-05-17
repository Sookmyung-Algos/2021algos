#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	vector <int> c;
	vector <int> ans;
	int n, m;

	cin >> n;
	for (int i = 0; i < n; i++) {
		int card;
		cin >> card;
		c.push_back(card); //카드에 적혀있는 정수를 입력받아 벡터 c에 저장
	}
	sort(c.begin(), c.end()); //카드에 적힌 수를 오름차순 정렬

	cin >> m;
	for (int i = 0; i < m; i++) {
		int key;
		cin >> key;
		ans.push_back(key);
		auto upper = upper_bound(c.begin(), c.end(), key); //key값 이상이 처음 나타나는 위치
		auto lower = lower_bound(c.begin(), c.end(), key);//key값보다 큰 값이 처음 나타나는 위치

		cout << upper - lower << " ";//upper와 lower의 차가 key값이 적힌 카드의 개수이므로 그 차를 ans 벡터에 저장
	}

	return 0;
}
