#include <iostream>
#include <algorithm>
#include <vector>;
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, x;
	int i, j, cnt = 0;
	int arr[100001];
	arr[0] = 0;
	
	
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
	cin >> x;

	sort(arr, arr + n+1);
	i = 1, j = n;

	while (i < j) {
		
		if (arr[i] + arr[j] == x) {
			cnt++;
			i++, j--;

		}
		else if (arr[i] + arr[j] < x) { // 커져야함
			i++;
		}
		else // 작아져야함
			j--;
		
	}
	cout << cnt;
	
}
