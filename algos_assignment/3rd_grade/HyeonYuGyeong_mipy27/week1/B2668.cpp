#include <iostream>
#include<algorithm>

using namespace std;

void dfs(int);
int arr[101];
bool visted[101]={false};
bool f[101];
int result[101];
int cnt=0;

int main() {
    int n;
    cin >> n;
    
    for (int i=1;i<=n;i++){
        cin >> arr[i];
    }
    for (int i=1;i<=n;i++){
        if (!visted[i]) dfs(i);
    }
    cout << cnt << '\n';
    sort(result,result+cnt);
    for (int i=0;i<cnt;i++){
        cout << result[i] << '\n';
    }
    return 0;
}
void dfs(int node){
    visted[node]=true;
    
    if (!visted[arr[node]]) dfs(arr[node]);
    else if (!f[arr[node]]) {
        result[cnt++]=node;
        for (int i=arr[node];i!=node;i=arr[i]) result[cnt++]=i;
    }
    f[node]=true;
}
