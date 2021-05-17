#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, len, ans;

void cut(int e) {
	if (m <= 0)
		return;
	else {
		e -= 10;
		ans++, m--;
		if (e > 10)
			cut(e);
		else if (e == 10)
			ans++;
		return;
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n >> m;
	vector<int> v;
	vector<int> v2;

	for (int i = 0; i < n; i++) {
		cin >> len;
		if (len < 10)	//10보다 길이가 작으면 v에 넣지 않고 건너뜀
			continue;
		v.push_back(len);
	}

	sort(v.begin(), v.end());

	//10의 배수인 경우
	for (int i = 0; i < v.size(); i++) {
		if (m <= 0)
			break;
		else if (v[i] == 10)
			ans++;
		else if (v[i] % 10 == 0)
			cut(v[i]);
		else v2.push_back(v[i]);	//10의 배수 아닌 것들 v2에 넣기
	}

	//10의 배수 아닌 경우
	for (int i = 0; i < v2.size(); i++)
		cut(v2[i]);

	cout << ans;
	return 0;
}

