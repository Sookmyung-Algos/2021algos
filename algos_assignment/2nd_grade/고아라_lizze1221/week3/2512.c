#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N, M;
	cin >> N;
	vector <int> v(N);
	int maxx = 0;
	for (int i = 0; i < N; i++) {
		cin >> v[i];
		maxx = max(maxx, v[i]); // 입력받은 예산 중 가장 큰 값을 maxx에 대입
	}
	cin >> M;
	
	int low = 0, high = maxx;
	int result;
	while (low <= high) { // 이분 탐색 진행
		int mid = (low + high) / 2; // 중간 값 mid에 대입
		long long sum = 0;
		for (int i = 0; i < N; i++) {
			sum += min(v[i], mid); // v[i]와 mid 중 최소값을 sum에 더하기
		}
		if (sum <= M) { // 만약 sum이 상한값과 같아지면
			result = mid; // result는 mid값이 되고
			low = mid + 1; // low 값 갱신해주기
		}
		else {
			high = mid - 1;
		}
	}
	cout << result << "\n";
	return 0;
}
