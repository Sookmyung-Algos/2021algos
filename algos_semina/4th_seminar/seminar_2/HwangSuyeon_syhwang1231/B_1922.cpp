#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 1001
using namespace std;

vector<pair<int, pair<int,int>>> edge;
int N, M;
int ans;
int parent[MAX];

int find(int a){
    if(parent[a] == a) return a;
    else return parent[a] = find(parent[a]);
}

bool sameParent(int x, int y){
    x = find(x);
    y = find(y);
    
    if(x==y) return true;
    else return false;
}

void Union(int x, int y){
    x = find(x);
    y = find(y);
    
    if(x!=y) parent[y] = x;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> N;
    cin >> M;
    int a, b, c;
    for(int i=0;i<M;i++){
        cin >> a >> b >> c;
        edge.push_back({c,{a,b}});
    }
    
    sort(edge.begin(), edge.end());  // first인 경로의 가중치를 기준으로 정렬
    
    for(int i=1;i<=N;i++)  // parent 초기화
        parent[i] = i;
    
    for(int i=0;i<M;i++){
        if(!sameParent(edge[i].second.first, edge[i].second.second)){
            Union(edge[i].second.first, edge[i].second.second);
            ans += edge[i].first;
        }
    }
    
    cout << ans;
    return 0;
}
