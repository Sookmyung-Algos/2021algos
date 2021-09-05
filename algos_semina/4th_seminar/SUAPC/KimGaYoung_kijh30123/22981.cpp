#include<iostream> 
#include<vector>
#include<algorithm> // min
using namespace std;

int n;
long long k, a=0, ans = 0;

int main() {
	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(false);
	cin >> n >> k;
	vector<long long> v;

	for (int i = 0; i < n; i++) {
		cin >> a;
		v.push_back(a); //입력받기
	}
	sort(v.begin(), v.end());

	for (int i = 1; i < n; i++) {
		a = v[0] * i + v[i] * (n - i);
		ans = max(ans, a);
	}
	cout << (k + ans - 1) / ans;
	return 0;
}
