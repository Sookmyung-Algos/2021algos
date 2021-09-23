#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n, m;
	int mat[15001]; //재료 고유 번호 수열

	cin >> n;
	cin >> m;
	for (int i = 0; i < n; i++) {
		cin >> mat[i];
	}

	sort(mat, mat + n); //수열의 원소 정렬

	int left = 0, right = n - 1; //작은 번호 재료의 인덱스 left,큰 번호 재료의 인덱스 right
	int cnt = 0, sum; //합이 m인 제작된 갑옷의 경우의 수 cnt, 두 재료의 합 sum

	while (left < right && left >= 0 && right <= n - 1) {
		sum = mat[left] + mat[right];
		if (sum > m) //m보다 합이 크다면 큰수의 인덱스 1 감소
			right--;
		else if (sum < m) //m보다 합이 작다면 작은수의 인덱스 1 증가
			left++;
		else { //합이 m과 같다면 cnt 1 증가하고 왼쪽 수 인덱스 1 증가 및 오른쪽 수 인덱스 1 감소
			cnt++;
			right--;
			left++;
		}
	}

	cout << cnt << endl; //결과 출력
}
