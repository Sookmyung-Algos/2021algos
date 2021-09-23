#include <iostream>
#include <vector>
using namespace std;

vector<long long> v;

int main(void) {
	int N, score, P;
	cin >> N >> score >> P;
	for (int i = 0; i < N; i++) {
		long long x;
		cin >> x;
		v.push_back(x);
	}
	int ans = 1;
	for (int i = 0; i < N; i++) {
		if (score < v[i]) ans++;  //송유진 등수 찾는 과정
	}
	if (N == P && score <= v[N - 1]) cout << -1 << '\n';  //송유진 점수가 리스트 끝값보다 작고, 리스트가 가득 차있다면 랭크에 들어가지 못함
	else cout << ans << '\n';
	return 0;
}
