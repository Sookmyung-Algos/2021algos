#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
    cin.tie(0);
	
	int N;
	vector<pair<int, int>> v;
	priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int, int>>> temp;
	
	cin >> N;
	for(int i=0;i<N;i++){
		int s, t;
		cin >> s >> t;
		v.push_back(make_pair(s, t));
	}
	sort(v.begin(), v.end());
	temp.push(make_pair(v[0].second, v[1].first));
	
	for(int i=1;i<v.size();i++){
		if(temp.top().first > v[i].first) temp.push(make_pair(v[i].second, v[i].first));
		else{
			temp.pop();
			temp.push(make_pair(v[i].second, v[i].first));
		}
	}
	

	cout << temp.size();
	
	return 0;
}
