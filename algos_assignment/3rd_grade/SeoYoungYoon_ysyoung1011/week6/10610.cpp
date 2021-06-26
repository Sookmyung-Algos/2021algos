#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool cmp(const int a, const int b) {
	return b < a;
}
int main(){
	vector <int> v;
	int  flag = 0;
	long long sum=0, ans = 0;
	string str;
	cin >> str;
	for (long long i = 0; i < str.length(); i++) {
		int k = (str[i]-'0');
		v.push_back(k);
		if (k == 0)flag = 1;
		sum += k;
	}
	
	if (flag == 0) {
		cout << -1; return 0;
	}
	if (sum % 3 != 0) {
		cout << -1;  return 0;
	}
	sort(v.begin(), v.end(), cmp);
	for (long long i = 0; i < v.size(); i++) {
		cout << v[i];
			}
	return 0;
}
