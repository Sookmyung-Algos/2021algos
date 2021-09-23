#include <iostream>
#include <map>
#include <unordered_map>
#include <string>
#include <vector>
#include <algorithm> 
#define MAX 100001
using namespace std;
int arr[MAX];

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);

	
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);
	int length = 21e8;

	int e = 0, s = 0;
	int cha = 0;
	while (1) {
		if (arr[e] - arr[s] >= m) {
			if (length > arr[e] - arr[s]) length = arr[e] - arr[s];
			s++;
		}
		else if (e >= n && s >= n) break;
		else e++;

	}
	cout << length;
	return 0;

}
