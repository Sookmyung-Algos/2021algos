#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<memory.h>
using namespace std;
int n;
vector<int>v;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	v.push_back(-1000000001);
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		if (num > v.back()) {
			v.push_back(num);
		}
		else {
			int idx = lower_bound(v.begin(), v.end(), num) - v.begin();
			v[idx] = num;
		}
	}
	v.erase(v.begin(), v.begin()+1);
	cout << v.size();
}
