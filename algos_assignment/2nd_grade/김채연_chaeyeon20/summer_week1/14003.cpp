#include <iostream>
#include <map>
#include <unordered_map>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm> 
#include <queue>
#include <math.h>
#define MAX 20001
using namespace std;

int arr[1000001];
int dp[1000001];
int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);
	
	
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];

	}
	
	vector <int> vect;
	vect.push_back(arr[0]);

	int cnt = 0;
	for (int i = 1; i < n; i++) {
		if (arr[i] > vect.back()) {
			vect.push_back(arr[i]);
			cnt++;
			dp[i] = cnt;
		}
		else {
			int pos = lower_bound(vect.begin(), vect.end(), arr[i]) - vect.begin();
			vect[pos] = arr[i];
			dp[i] =pos;
		}
	}
	int size = vect.size()-1;
	vector <int> ans;
	for (int i = n - 1; i >= 0; i--) {
		if (dp[i] == size) {
			ans.push_back(arr[i]);
			size--;
		}
	}

	cout << vect.size() << endl;
	int k = ans.size();
	for (int i = 0; i < k; i++) {
		cout << ans.back() << " ";
		ans.pop_back();
	}
	return 0;

}
