/*
 트리의 지름 구하기
 1. 임의의 정점에서 가장 먼 정점 구하기
 2. 구한 정점으로부터 가장 먼 정점 구하기
 3. 두 정점 사이의 거리 = 트리의 지름
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define MAX 1000000
using namespace std;

int n;
vector <pair<int,int>> v[MAX];
bool visit[MAX];
int maxD=0,maxP=0;

void dfs(int a,int dis);

int main(){
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    
    int x,y,z;
    cin>>n;
    for (int i=0;i<n-1;i++){
        cin>>x>>y>>z;
        v[x].push_back({y,z});
        v[y].push_back({x,z});
    }
    dfs(1,0);
    int a=maxP;
    
    memset(visit,false,sizeof(visit));
    maxD=0;
    dfs(maxP,0);
    int b=maxP;
    
    memset(visit,false,sizeof(visit));
    maxD=0;
    visit[b]=true;
    dfs(a,0);
    int a_result=maxD;
    
    memset(visit,false,sizeof(visit));
    maxD=0;
    visit[a]=true;
    dfs(b,0);
    int b_result=maxD;
    
    if (a_result>b_result)
        cout<<a_result;
    else
        cout<<b_result;
}

void dfs(int a,int dis){
    if (visit[a])
        return;
    
    visit[a]=true;
    if (maxD<dis){
        maxD=dis;
        maxP=a;
    }
    
    for (int i=0;i<v[a].size();i++){
        dfs(v[a][i].first,dis+v[a][i].second);
    }
}
