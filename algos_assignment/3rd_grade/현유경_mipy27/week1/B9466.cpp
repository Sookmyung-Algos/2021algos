#include <iostream>
#include <algorithm>
using namespace std;

void dfs(int);
int t,n,cnt;
int arr[100001];
bool visited[100001];
bool finished[100001];

void init(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main() {
    init();
    cin >> t;
    
    for (int i=0;i<t;i++){
        cin >> n;
        cnt=0;
        
        for (int j=1;j<=n;j++){
            cin >> arr[j];
            visited[j]=false;
            finished[j]=false;
        }
        for(int k=1;k<=n;k++){
            if (!visited[k]) dfs(k);
        }
        cout << n-cnt << '\n';
    }
    return 0;
}

void dfs(int node){
    visited[node] = true;
    
    int next = arr[node];
    if (!visited[next]) dfs(next);
    else if (!finished[next]){
        for (int i=next;i!=node;i=arr[i]) cnt++;
        cnt++;
    }
    finished[node]=true;
}
