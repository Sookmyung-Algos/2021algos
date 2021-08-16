#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n,m;
bool visit[10];
vector <int> v;

void bt(int cnt);

int main(){
    
    
    cin>>n>>m;
    bt(0);
}

void bt(int cnt){
    if (cnt==m){
        for (int i=0;i<v.size();i++)
            cout<<v[i]<<' ';
        cout<<'\n';
        return;
    }
    
    for (int i=1;i<=n;i++){
        if (!visit[i]){
            visit[i]=true;
            v.push_back(i);
            bt(cnt+1);
            visit[i]=false;
            v.pop_back();
        }
    }
}
