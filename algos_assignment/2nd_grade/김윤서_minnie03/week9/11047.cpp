#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n,k;
	int a[12];

	cin>>n>>k; //n과 k를 입력받고
	for (int i = 0; i < n; i++) { //n개의 줄에
		cin>>a[i]; //동전의 가치 입력받음
	}

	int cnt = 0; //동전의 개수
	for (int i = n-1; i>= 0; i--) {
		if (k == 0) break; //k가 0이 되면 멈춤
		if (a[i] != 0) { //가치가 0이 아닌 조건에서
			cnt += k / a[i]; //가치가 큰 동전부터 k로 나누어 필요한 개수만큼 더해줌
			k %= a[i]; //위에서 나눈 만큼 빼고 그 나머지만을 남김
		}
	}

	cout << cnt << endl ; //최종적으로 필요한 동전 개수의 최솟값을 출력
	return 0;

}
