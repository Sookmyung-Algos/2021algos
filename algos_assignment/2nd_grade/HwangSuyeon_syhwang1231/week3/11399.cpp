//baekjoon 11399 ATM

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void) {
	int n;	//사람의 수
	int tmp;
	int sum = 0;	//대기 시간 합
	vector <int> time;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> tmp;
		time.push_back(tmp);
	}

	sort(time.begin(), time.end());

	for (int i = 0; i < n; i++) {	//n명의 사람들의 대기 시간 구하기
		for (int j = 0; j <= i; j++) {	//맨 앞부터 자기번째까지 대기시간 합
			sum += time[j];
		}
	}

	cout << sum;

	return 0;
}
