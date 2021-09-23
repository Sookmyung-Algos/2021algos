#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <map>
#include <unordered_map>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm> 
#include <queue>
#include <math.h>
#include <time.h>
#define MAX 100001
using namespace std;
vector <pair<int,int>> vect;
int arr1[MAX];
int arr2[MAX];
int dp[10001];
int main() {
	
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);
	
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		arr1[a] = i;
	}

	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		arr2[i] = a;
		vect.push_back({ arr1[a],i });
		
	}
	sort(vect.begin(), vect.end());

	vector <int> result;
	result.push_back(vect[0].second);
	int cnt = 0;
	for (int i = 1; i < n; i++) {
		if (result.back() < vect[i].second) {
			result.push_back(vect[i].second);
			cnt++;
			dp[i] = cnt;
		}
		else {
			int pos = lower_bound(result.begin(), result.end(), vect[i].second) - result.begin();
			result[pos] = vect[i].second;
			dp[i] = pos;
		}
	}
	int size = result.size() - 1;
	vector <int> ans;
	for (int i = n - 1; i >= 0; i--) {
		if (dp[i] == size) {
			ans.push_back(vect[i].second);
			size--;
		}
	}
	vector<int> arin;
	cout << result.size() << "\n";
	int k = ans.size();
	for (int i = 0; i < k; i++) {
		arin.push_back(arr2[ans.back()]);
		
		ans.pop_back();
	}
	sort(arin.begin(), arin.end());
	k = arin.size();
	for (int i = 0; i < k; i++) {
		cout << arin[i] << " ";
	}
	return 0;
}
