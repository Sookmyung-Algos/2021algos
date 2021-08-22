#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n,x;
	int a[100001]; //수열

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	cin >> x;

	sort(a, a + n); //수열의 원소 정렬

	int left = 0, right = n - 1; //a(i)의 인덱스 left,a(j)의 인덱스 right
	int cnt = 0,pair; //조건 만족하는 쌍의 개수 cnt, a(i)+a(j)의 값 pair

	while (left<right&&left>=0&&right<=n-1) {
		pair = a[left] + a[right];
		if (pair > x) //x보다 합이 크다면 큰수의 인덱스 1 감소
			right--;
		else if (pair < x) //x보다 합이 작다면 작은수의 인덱스 1 증가
			left++;
		else { //합이 x와 같다면 cnt 1 증가하고 왼쪽 수 인덱스 1 증가 및 오른쪽 수 인덱스 1 감소
			cnt++;
			right--;
			left++;
		}
	}

	cout << cnt << endl; //결과 출력
}
