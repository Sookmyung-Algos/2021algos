#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<algorithm>
using namespace std;
int n, a, b, c;
int arr[101];
int main() {
	cin >> n >> a >> b >> c;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n, greater<>());
	int price = a;
	int cal = c;
	int ans = c / a; //초기화 -> 도우만 했을 때
	for (int i = 0; i < n; i++) {
		price += b;
		cal += arr[i];
		ans = max(ans, cal / price);
	}
	cout << ans;
}
