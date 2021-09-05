#include <cstdio>
#include <queue>
#include <cmath>
using namespace std;

pair<float,float> loc[101];
int Parent[101];
int Rank[101];
priority_queue<pair<float, pair<int,int>>, vector<pair<float, pair<int,int>>>, greater<pair<float, pair<int,int>>>> pq;

int Find(int x){
    if(Parent[x]==x)
        return x;
    return Parent[x]=Find(Parent[x]);
}

void Union(int x, int y){
    x=Find(x);
    y=Find(y);

    if(x==y)
        return;
    if(Rank[x]>Rank[y]){
        Parent[y]=x;
    }
    else{
        if(Rank[x]==Rank[y])
            Rank[y]++;
        Parent[x]=y;
    }
    
}

int main(){
    int n;
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        scanf("%f %f", &loc[i].first, &loc[i].second);
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            float tmp=sqrt(pow((loc[i].first-loc[j].first),2)+pow((loc[i].second-loc[j].second),2));
            pq.push({tmp,{i,j}});
        }
    }
    for(int i=0;i<n;i++){
        Parent[i]=i;
        Rank[i]=1;
    }
    float ans=0;
    while(!pq.empty()){
        float dist=pq.top().first;
        pair<int,int> v=pq.top().second;
        pq.pop();
        //사이클 체크
        if(Find(v.first)==Find(v.second))
            continue;
        ans+=dist;
        Union(v.first, v.second);
    }
    printf("%.2f", ans);
}
