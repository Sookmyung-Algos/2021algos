// 22951: 송이의 카드 게임 (Silver 5)
#include <iostream>
#include <vector>
using namespace std;

int N, K;
vector<pair<int, int>> cards;  // first: 사람 번호, second: 카드

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < K; j++) {
			int tmp;
			cin >> tmp;
			cards.push_back({ i,tmp });
		}
	}

	int idx = 0;
	while (cards.size() != 1) {
		int cardNum = cards[idx].second;
		cards.erase(cards.begin() + idx);
		idx--;
		if (idx < 0)
			idx = cards.size() - 1;
		for (int i = 0; i < cardNum; i++) {
			idx++;
			if (idx >= cards.size())
				idx = 0;
		}
	}

	cout << cards[0].first << ' ' << cards[0].second;
	return 0;
}
