#include<bits/stdc++.h>
using namespace std;
int main() {
	vector<string> v = { "c=","c-","dz=","d-","lj","nj","s=","z=" };
	int a;
	string str;
	cin >> str;
	for (int i = 0; i < 8; i++) {
		a = str.find(v[i]);
		for (; a != string::npos; a = str.find(v[i])) {
			str.replace(a, v[i].length(), "@");
		}
	} 
	cout << str.length();
}
