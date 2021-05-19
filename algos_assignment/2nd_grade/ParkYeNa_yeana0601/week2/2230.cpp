#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(0); cout.tie(0); //fast I/O
	ios_base::sync_with_stdio(false);

	int n, m;
	int arr[100000];
	cin >> n >> m;

	for (int i = 0; i < n; i++) { //배열 입력
		cin >> arr[i];
	}

	int s = 0, e = 0;
	int cnt=0, dif = 0, min_dif=2000000001;
	sort(arr, arr + n); //배열 오름차순 정렬

	while (s<=e && e!=n) {
		dif = arr[e] - arr[s];
		if (dif == m) { //dif == m이면 최소값. break
			min_dif = m;
			break;
		}
		else if (dif > m) { //dif>m인 동안 -> 아니면 e++
			if (dif<min_dif) min_dif = dif; //dif <min_dif 면 dif를 min_dif에 저장.
			s++;
		}
		else e++;
	}

	cout << min_dif;
	return 0;
}
