#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(string x, string y) {
	if (x.length() == y.length()) {
		return x < y;
	}	// 길이가 같다면 사전 순으로
	else {
		return x.length() < y.length();
	}	// 길이가 짧은것부터
}

int main() {
	int N;
	cin >> N;
	vector<string> v(N);
	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end(), cmp);	// cmp함수에 따라 정렬
	cout << v[0] << endl;
	for (int i = 0; i < N; ++i)
	{
		if (i > 0 && (v[i] == v[i - 1]))
			continue;
		cout << v[i] << endl;
	}	// 같은 단어가 여러 번 입력되지 않도록 한 번씩만 출력
	return 0;
}
