#include <iostream>
#include <vector>
using namespace std;

int number;
int n;
int virus = 0;
int c[101];
vector<int> v[101];

int dfs(int x) {
	if(!c[x]){
		c[x] = true;
	    virus++;
        for(int i=0;i<v[x].size();i++){
            int y=v[x][i];
            dfs(y);
        }
	}
	return virus;
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

	cin >> number;
	for(int i=1;i<=number;i++){
		c[i] = 0;
	}
	cin >> n;
	int s,t;
	for(int i=0;i<n;i++){
		cin >> s >> t;
		v[s].push_back(t);
		v[t].push_back(s);
	}
	 cout << dfs(1)-1;
	 return 0;
}
