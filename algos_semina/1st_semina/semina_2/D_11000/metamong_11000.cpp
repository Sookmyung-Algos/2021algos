#include<bits/stdc++.h>
using namespace std;
int main() {
	int n;
	vector<pair<int,int>>v;
	priority_queue<int,vector<int>,greater<int>>q;
	cin>>n;
	for(int i=0; i<n; i++){
		int x,y;
		cin>>x>>y;
		v.push_back(make_pair(x,y));
	}
	sort(v.begin(),v.end());
	q.push(v[0].second);
	for(int i=1; i<n; i++){
		if(v[i].first>=q.top()) q.pop();
		q.push(v[i].second);
	}
	cout<<q.size()<<"\n";
}
