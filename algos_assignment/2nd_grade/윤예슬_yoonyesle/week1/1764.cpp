#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
int n;
string a[20001];
bool comp(string a, string b){
	return a<b;
}
int main() {
	int n, m, i;
	string a[1000001], b[500001];
	cin >> n >> m;
	for(int i=0; i<n; i++)
		cin >> a[i];
	for(int i=0; i<m; i++)
		cin >> a[i+n];
	sort(a, a+n+m, comp);
	int j=0;
	for(int i=0; i<n+m-1; i++)
		if(a[i] == a[i+1]) b[j++]=a[i];
	sort(b, b+j, comp);
	cout << j << '\n';
	for(i=0; i<j; i++)
		cout << b[i] << '\n';
	return 0;
}
