#include <iostream>
#include <algorithm>
using namespace std;

struct num{
    int x;
    int y;
}v[100000];

bool compare(struct num a,struct num b){
    if (a.x==b.x)
        return a.y<b.y;
    return a.x<b.x;
}

int main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(false);
    
    int N;
    cin>>N;
    for (int i=0;i<N;i++)
    {
        cin>>v[i].x>>v[i].y;
    }
    sort(v,v+N,compare);
    for (int i=0;i<N;i++)
        cout<<v[i].x<<' '<<v[i].y<<'\n';
}
