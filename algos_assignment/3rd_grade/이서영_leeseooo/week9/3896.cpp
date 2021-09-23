#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
#define MAX 1299709+1
int t;
int arr[MAX];
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> t;
	for (int i = 2; i < MAX; i++) {
		arr[i] = i;
	}
	for (int i = 2; i*i < MAX; i++) {
		if (arr[i] == i) {
			for (int j = i * i; j < MAX; j += i) {
				if (arr[j] == j) {
					arr[j] = i;
				}
			}
		}
	}
	arr[0] = arr[1] = -1;
	while (t--) {
		int num;
		cin >> num;
		if (arr[num] == num) {
			cout << 0 << '\n';
			continue;
		}
		int res = 1; //초기화는 num자기 자신 포함
		int start = num - 1;
		for (int i = start; i > 2; i--) {
			if (arr[i] == i)break;
			res++;
		}
		start = num + 1;
		for (int i = start; i < MAX; i++) {
			if (arr[i] == i)break;
			res++;
		}
		cout << res + 1 << '\n';
	}
}
