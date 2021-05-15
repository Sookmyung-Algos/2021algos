#include<bits/stdc++.h>
using namespace std;
bool tmp(pair<int,int>a, pair<int,int>b)
{
	if (a.first==b.first) return a.second<b.second;
	return a.first<b.first;
}
int main()
{
	vector<pair<int,int>> v;
	int n;
	cin>>n;
	for (int i=0; i<n; i++){
		int x,y;
		cin>>x>>y;
		v.push_back(make_pair(x,y));
	}
	sort(v.begin(), v.end(), tmp);
	for (vector<pair<int,int>>::iterator t=v.begin(); t!=v.end(); t++)
		cout<<t->first<<" "<<t->second<<"\n";
	return 0;
}
