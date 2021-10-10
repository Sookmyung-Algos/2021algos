#include<iostream>
#include<vector>
#include<queue>
#include<string>

using namespace std;

int main() {
	int n, k;
	cin >> n >> k;

	vector<string>v;
	queue<int>q[21];
	v.resize(n + 1);

	for (int i = 1; i <= n; i++) {
		cin >> v[i];
	}

	long long res = 0;
	for (int i = 1; i <= n; i++) {
		int len = v[i].length();
		while (!q[len].empty() && i - q[len].front() > k)   //해당 길이의 제일 앞에 있는 친구와 차이가 K보다 크면 좋은 친구 아님
			q[len].pop();
		res += q[len].size();
		q[len].push(i);
	}
	cout << res;
	return 0;
}