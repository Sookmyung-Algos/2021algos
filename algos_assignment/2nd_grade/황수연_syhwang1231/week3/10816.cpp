//baekjoon 10816 숫자카드2

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void) {
	int n, tmp, m;
	vector<int> cards;
	vector<int> search;

	cin >> n;	//숫자카드 개수 입력

	for (int i = 0; i < n; i++) {
		cin >> tmp;
		cards.push_back(tmp);
	}
	sort(cards.begin(), cards.end());	//숫자카드 오름차순 정렬

	cin >> m;
	for (int i = 0; i < m; i++) {	//찾고자 하는 수 m개 입력
		cin >> tmp;
		search.push_back(tmp);
	}
	
	for (int i = 0; i < m; i++) {
		int start = lower_bound(cards.begin(), cards.end(), search[i]) - cards.begin();		//search[i]이상이 값이 처음 나오는 위치
		int end = upper_bound(cards.begin(), cards.end(), search[i]) - cards.begin();	//search[i] 초과의 값이 처음 나오는 위치
		cout << end - start << " ";
	}

	return 0;
}
