#include <iostream>
using namespace std;

int n, m;
int a[1000001];
int ms=0;

void dfs(int x, int size, int cnt){
    if(cnt==m || x==n){
        ms=max(ms, size);
        return;
    }
    dfs(x+1, size+a[x+1], cnt+1);
    dfs(x+2, size/2+a[x+2], cnt+1);
    return;
}

int main(){
    cin >> n >> m;
    for(int i=1;i<=n;i++) cin >> a[i];
    dfs(0, 1, 0);
    cout << ms;
}
