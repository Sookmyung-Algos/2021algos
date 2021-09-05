#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n, k, spc;
	vector<int> v;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int taste;
		cin >> taste;
		v.push_back(taste);
	}
	cin >> k;
	spc = n / k;	
	for (int i = 0; i < v.size(); i += spc) 
		sort(v.begin() + i, v.begin() + i + spc);
	
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << " ";
 }
