#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector <int> v[100001];
int ans[100001];

void dfs(int x){
	for(int i = 0; i< v[x].size(); i++){
		int next = v[x][i];
		if(ans[next] == 0){
			ans[next] = x;
			dfs(next);
		}
	}
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin>>n;

  for(int i = 0; i<n-1; i++){
	  int a, b;
	  cin>>a>>b;

	  v[a].push_back(b);
	  v[b].push_back(a);
  }
  //cout<<"done";
  ans[1] = 1;
  //cout<<"start";
  dfs(1);
  //cout<<"finished";

  for(int i = 2; i<=n; i++){
	  cout<<ans[i]<<"\n";
	  //endl 사용하면 시간초과 남. 이걸로 20분 잡아먹음...개빡침
  }

  return 0;
}
