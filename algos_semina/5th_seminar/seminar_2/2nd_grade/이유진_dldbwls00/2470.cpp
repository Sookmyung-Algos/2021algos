#include <iostream>
#include <algorithm>
using namespace std;
//그냥 for문을 이용해 배열을 하나하나 비교할 경우 시간초과 발생
int arr[100000];
int ans[2];

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n; //전체 용액의 수
	cin >> n; 
	for (int i = 0; i < n; i++)	cin >> arr[i];
	sort(arr, arr + n);

	int left = 0, right = n - 1; //투포인터
	int value, ans1 = arr[left], ans2 = arr[right], ans = ans1 + ans2;
	while (left < right) {
		value = arr[left] + arr[right];
		if (abs(ans) > abs(value)) {
			ans = value;
			ans1 = arr[left];
			ans2 = arr[right];
		}
		if (value <= 0) left++;
		else right--;
	}
	cout << ans1 << " " << ans2;
	return 0;
}
