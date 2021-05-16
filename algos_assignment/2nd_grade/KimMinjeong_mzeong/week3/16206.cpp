#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, a, cnt;

void cut(int length) {
	if (m <= 0) return;
	else {
		length -= 10;
		cnt++; m--;
		if (length == 10) cnt++;
		else if (length > 10) cut(length);
		return;
	}
}

int main() { // 길이가 짧은 순으로 롤케이크 자름(계속 실패했다고 뜸) -> 10의 배수인 롤케이크 먼저 잘라야 함!(v1, v2로 구분해 자름)
	vector<int> v1;
	vector<int> v2;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> a;
		if (a < 10) continue;
		v1.push_back(a);
	}
	sort(v1.begin(), v1.end());

	for (int i = 0; i < v1.size(); i++) {
		if (m <= 0) break;
		else if (v1[i] == 10) cnt++;
		else if (v1[i] % 10 == 0) cut(v1[i]);
		else v2.push_back(v1[i]);
	}

	for (int i = 0; i < v2.size(); i++) cut(v2[i]);

	cout << cnt;
	return 0;
}
