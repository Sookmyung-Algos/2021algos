//baekjoon 1920 수 찾기

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	int n, m, tmp, find;
	vector<int> num;
	vector<int> search;

	cin >> n;
	for (int i = 0; i < n; i++) {	//n개의 자연수 입력받기
		cin >> tmp;
		num.push_back(tmp);
	}
	sort(num.begin(), num.end());	//이진탐색 위해 오름차순 정렬

	cin >> m;
	for (int i = 0; i < m; i++) {	//찾고자 하는 수 m개 입력
		cin >> tmp;
		search.push_back(tmp);

	}

	for (int i = 0; i < m; i++) {
		if (binary_search(num.begin(), num.end(), search[i]))	//이진탐색 결과 존재하면 1출력
			cout << 1 << "\n";
		else
			cout << 0 << "\n";
	}
	return 0;
}
