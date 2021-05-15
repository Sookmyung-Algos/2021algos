#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[9]={0,};
bool ch[9]={0,};
void dfs(int num,int cnt)
{
    if(cnt==m){
        for(int i=0; i<m; i++){
            cout<<a[i]<<" ";
        }
        cout<<"\n";
        return;
    }
    for(int i=num; i<=n; i++){
            ch[i]=1;
            a[cnt]=i;
            dfs(i,cnt+1);
            ch[i]=0;
    }
}
int main() {
    cin>>n>>m;
    dfs(1,0);
}
