#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool sort_second(pair<int, int> a, pair<int, int> b){
	if(a.second < b.second){
		return true;
	}
	else if (a.second == b.second){
		return (a.first < b.first);
	}

	return false;
}

int main(void){
	cin.tie(NULL);
    ios::sync_with_stdio(false);
	
    int n;
    cin>>n;

    vector<pair<int,int>> v(n);

    for(int i = 0; i < n; i++){
        cin>>v[i].first;
        cin>>v[i].second;
    }
    sort(v.begin(), v.end(), sort_second);

    for(int i = 0; i < v.size(); i++){
        cout<<v[i].first<<" "<<v[i].second<<'\n';
    }
}
