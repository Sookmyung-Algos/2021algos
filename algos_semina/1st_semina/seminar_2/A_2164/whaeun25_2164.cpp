#include<iostream>
#include<algorithm>
#include<deque>

using namespace std;

deque<int> card;

int main() {

	int n;

	cin >> n;

	for (int i = n; i > 0; i--) {
		card.push_back(i);
	}

	while (card.size() >= 2) {
		card.pop_back();
		card.push_front(card[card.size() - 1]);
		card.pop_back();
	}

	cout << card[0];
}
