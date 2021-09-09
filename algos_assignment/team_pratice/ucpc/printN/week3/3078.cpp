#include <iostream>
#include <string>
#include <queue>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0); //입출력속도개선

	int N, K;
	queue<int> q[21];
	long long ans = 0; //ans값이 int보다 크게나옴

	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		string str;
		cin >> str; //문자열 하나씩 입력받고

		int len = str.length();

		while (!q[len].empty() && i - q[len].front() > K) {
			q[len].pop();
		} //등수차이가 기준보다 많이나면 빼내기
		ans += q[len].size(); //안에 남은건 전부 친구
		q[len].push(i);
	}

	cout << ans;

	return 0;
}
