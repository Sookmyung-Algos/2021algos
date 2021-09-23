#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int t;
	cin >> t;
	int cnt[200001] = { 0, }; //각 케이스 마다 도둑이 빠져나가는 경우

	for (int i = 0; i < t; i++) { //테스트 케이스 개수 만큼 반복
		int n, m, k;
		long long money[200001]; //각 집에서 보관중인 돈의 금액

		scanf("%d %d %d", &n, &m, &k);
		for (int j = 0; j < n; j++) {
			cin >> money[j];
		}

		for (int l = 0; l < n; l++) {
			long long sum = 0; 
			for (int o = 0; o < m; o++) { //m개의 연속된 집에 보관되어 있는 금액을 모두 더함
				sum += money[(l + o) % n];
			}
			if (sum < k) cnt[i]++; //sum이 k보다 작으면 cnt 1 증가
		}
	}

	for (int i = 0; i < t; i++) { //각 케이스마다
		cout << cnt[i] << endl; //도둑이 무사히 빠져나가는 방법의 수 출력
	}

	return 0;
}
