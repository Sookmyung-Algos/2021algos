#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
#include<queue>
using namespace std;
int compare(string a,string b) {
	if (a.length() == b.length())
		return a < b; //길이 같으면 사전순
	return a.length() < b.length();//길이순
}
int main() {
	int n;
	string s;
	vector<string>v;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s;
		v.push_back(s);
	}
	sort(v.begin(),v.end(), compare);
	cout << v[0] << "\n";
	for (int i = 1; i < n; i++) {
		if (v[i] == v[i-1])
			continue;
		cout << v[i] << "\n";
	}
}
