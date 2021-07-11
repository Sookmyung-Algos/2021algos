// baekjoon 1431 시리얼 번호

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int serialSum(string a);
bool comp(string a, string b);

int serialSum(string a) {
	int res = 0;
	for (int i = 0; i < a.length(); i++) {
		if ((a[i] - '0') >= 1 && (a[i] - '0') <= 9)  // 숫자이면 (0은 더할 필요 없으므로 1이상부터 고려)
			res += (a[i] - '0');
	}
	return res;
}

bool comp(string a, string b) {
	if (a.length() != b.length()) {  // 조건 1(길이 순)
		return a.length() < b.length();
	}
	else {
		// 시리얼 번호의 숫자 합하기
		int aSum = serialSum(a);
		int bSum = serialSum(b);

		if (aSum != bSum)
			return aSum < bSum;  // 조건 2(숫자 합 순)
		else
			return a < b;  // 조건 3(사전 순)
	}
}

int main(void) {
	int n;  // n: 기타 개수(n<=1000)
	cin >> n;

	vector<string> guitar(n);

	for (int i = 0; i < n; i++) {
		cin >> guitar[i];
	}

	sort(guitar.begin(), guitar.end(), comp);

	for (int i = 0; i < n; i++) {
		cout << guitar[i] << "\n";
	}
	return 0;
}
