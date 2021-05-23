#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b) {
	if (a.first == b.first) //x좌표가 같다면
		return a.second < b.second; //y좌표가 증가하는 순서로
	else //아니라면 x좌표가 증가하는 순서로
		return a.first < b.first;
}

int main() {
	int N;
	cin >> N;

	vector<pair<int, int>> c;

	int x = 0, y = 0;
	for (int i = 0; i < N; i++) {
		cin >> x >> y;
		c.push_back(make_pair(x, y)); //x,y로 한 페어를 만들어 벡터 c에 푸쉬해줌
	}

	sort(c.begin(), c.end(), cmp); //정렬

	for (auto it = c.begin(); it != c.end(); it++) {
		cout << it->first << " " << it->second << '\n'; //출력
	}
}
