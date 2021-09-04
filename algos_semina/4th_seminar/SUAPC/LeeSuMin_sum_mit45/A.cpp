#include <iostream>
#include <algorithm>
#define MAX 1000000000+1
#define ll long long
using namespace std;

ll N, K;
ll arr[200001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + N);
	ll mmax = -1;
	ll idx = 0;

	for (ll i = N - 1; i > 0; i--) {
		ll x = arr[i] * (N - i) + arr[0] * i;
		if (mmax < x) {
			mmax = x;
			idx = i;
		}
	}
	ll time;
	if (K % mmax == 0) // 시간이 딱 떨어지는 경우
		time = K / mmax;
	else
		time = (K / mmax) + 1;

	cout << time;
}
