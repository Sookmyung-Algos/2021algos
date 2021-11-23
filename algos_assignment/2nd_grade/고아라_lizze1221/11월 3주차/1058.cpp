#include<bits/stdc++.h>
using namespace std;

int N;
int cnt = 0, res = 0;
vector<int> a[51];
bool ch[51];

void DFS(int L,int v){
    ch[v] = true;
    if(L == 2) return ;
    
    for(int i=0; i<a[v].size(); i++){
        DFS(L+1, a[v][i]);   
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    
    cin >> N;
    char tmp;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            cin >> tmp;
            if(tmp == 'Y') a[i].push_back(j);
        }
    }

    for(int i=1; i<=N; i++){
        memset(ch, false, sizeof(ch));
        cnt = 0;
        DFS(0,i);
        for(int i=1; i<=N; i++){
            if(ch[i] == true) cnt++;
        }
        res = max(res, cnt);
    }
    
    cout<<res-1<<endl;
   
    return 0;
}
