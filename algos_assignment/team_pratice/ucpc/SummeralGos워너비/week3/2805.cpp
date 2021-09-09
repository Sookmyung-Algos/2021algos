//#2805 //tree배열 크기 주의
#include <iostream>
using namespace std;
int n;
long long m;
long long tree[1000001]; //나무 길이 입력받을 배열

long long searchheight(long long max) {
	long long left = 0, right = max;
	long long before = 0; //전에 시행했을때의 mid 길이

	while (left <= right) {
		long long mid = (left + right) / 2; //절단기 높이
		long long sum = 0; //가져가는 나무의 총 길이

		for (int i = 0; i < n; i++) {
			if (tree[i] > mid) { //절단 높이보다 긴 나무들만 
				sum += tree[i] - mid; //잘라낸 길이 sum에 더함
			}
		}
		if (sum >= m) { //sum이 m보다 크거나 같으면 (가져가야 할 나무의 길이 최솟값은 충족)
			if (before < mid) { //만약 이전에 한 것보다 절단 높이가 길다면
				before = mid; //현재 더 높은 절단 높이를 before에 저장
			}
			left = mid + 1; //절단기 높이를 더 긴 길이로
		}
		else { //sum이 m보다 작으면 (가져가야 할 나무의 길이 최솟값 미충족->절단기 높이를 더 짧은 길이로)
			right = mid - 1;
		}
	}
	return before; //최종으로 저장된 mid값 리턴
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	long long max = -1;
	cin >>n>> m; //나무의 수와 가져가려고 하는 나무의 길이
	for (int i = 0; i < n; i++) {
		cin >> tree[i]; //나무 높이 입력
		max = (max > tree[i] ? max : tree[i]); //최대 나무 높이 구함
	}
	long long result=searchheight(max);
	
	cout << result;
	return 0;
}
