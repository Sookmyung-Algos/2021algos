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
    }
    for(int i=num; i<=n; i++){
        if(ch[i]==0)
        {
            ch[i]=1;
            a[cnt]=i;
            dfs(i+1,cnt+1);
            ch[i]=0;
        }
    }
}
int main() {
    cin>>n>>m;
    dfs(1,0);
}
