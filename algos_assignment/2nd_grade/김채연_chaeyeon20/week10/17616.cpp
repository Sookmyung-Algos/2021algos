#include <vector>
#include <iostream>
#include <queue>

using namespace std;

vector<int> vr[100001];
vector<int> v[100001];
int n,m,k;
char check[100001];
queue<int> q;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	cin>>n>>m>>k;
	for(int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
		vr[a].push_back(b);
		v[b].push_back(a);
	}
	int up=0,down=0;
	check[k]=1;
	q.push(k);
	while(!q.empty()){
		int x=q.front();
		q.pop();
		for(int i=0;i<v[x].size();i++){
			int next = v[x][i];
			if(check[next] == 0){
				check[next] = 1;
				up++;
				q.push(next);
			}
		}
	}
	q.push(k);
	while(!q.empty()){
		int x=q.front();
		q.pop();
		for(int i=0;i<vr[x].size();i++){
			int next = vr[x][i];
			if(check[next] == 0){
				check[next] = 1;
				down++;
				q.push(next);
			}
		}
	}
	cout<<1+up<<" "<<n-down;
}




















