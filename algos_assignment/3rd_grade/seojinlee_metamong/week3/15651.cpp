#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[9]={0,};
bool ch[9]={0,};
void dfs(int cnt)
{
    if(cnt==m){
        for(int i=0; i<m; i++){
            cout<<a[i]<<" ";
        }
        cout<<"\n";
        return;
    }
    for(int i=1; i<=n; i++){
            ch[i]=1;
            a[cnt]=i;
            dfs(cnt+1);
            ch[i]=0;
    }
}
int main() {
    cin>>n>>m;
    dfs(0);
}
