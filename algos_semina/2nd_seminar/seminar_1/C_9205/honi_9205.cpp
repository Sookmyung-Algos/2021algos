#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

vector<pair<int, int>> v;
int result;
int visit[103];
int t,n,x,y;

void dfs(int a, int b){
    int num;
    
    num=abs(v[n+1].first-a)+abs(v[n+1].second-b);       //페스티벌이 열리는 위치와 현위재 사이의 거리
    if (num<=1000){         //50미터보다 적은 경우(맥주가 남는 경우)
        result=1;           //행복하게 도착 가능
        return;
    }
    
    for (int i=1;i<=v.size();i++){
        if (visit[i]==1)
            continue;
        
        num=abs(v[i].first-a)+abs(v[i].second-b);       //편의점과 현위치 사이의 거리
        if (num>1000)       //편의점이 50미터보다 더 멀리 있는 경우
            continue;
        
        else{
            visit[i]=1;     //편의점 방문
            dfs(v[i].first,v[i].second);        //재귀
        }
    }
}

int main(){
    
    cin>>t;
    while (t--){
        v.clear();
        memset(visit, 0, sizeof(visit));
        
        cin>>n;
        for (int i=0;i<n+2;i++){        //집, 편의점, 페스티벌 위치
            cin>>x>>y;
            v.push_back(make_pair(x,y));
        }
        
        result=0;
        dfs(v[0].first,v[0].second);
        
        if (result)             //행복하게 도착
            cout<<"happy"<<'\n';
        else                    //슬프게 도착
            cout<<"sad"<<'\n';
    }
}
