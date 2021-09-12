#include <iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
int n;
string s;
vector<string>v;
bool cmp(string a,string b){
	if(a.length() == b.length()){
		int aSum=0;
		int bSum=0;
		for(int i=0;i<a.length();i++){
			if(a[i] >= 'A' && a[i] <= 'Z')continue;
			aSum += a[i]-'0';
		}
		for(int i=0;i<b.length();i++){
			if(b[i] >= 'A' && b[i] <= 'Z')continue;
			bSum += b[i]-'0';
		}
		if(aSum == bSum){
			return a < b;
		}
		return aSum < bSum;
	}
	return a.length() < b.length();
}
int main() {
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> s;
		v.push_back(s);
	}
	sort(v.begin(),v.end(),cmp);
	for(int i=0;i<n;i++){
		cout << v[i] << '\n';
	}
	return 0;
}
