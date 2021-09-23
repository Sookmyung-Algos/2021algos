#include <cstdio>
#include <queue>
using namespace std;

int n, k;
int place[100001];
int d[2]={-1, 1};

int bfs(){
    queue<int> q;
    place[n]=0;
    q.push(n);
    while(!q.empty()){
        int cur=q.front();
        q.pop();
        for(int i=0;i<3;i++){
            int next;
            if(i==2)
                next=cur*2;
            else
                next=cur+d[i];
            if(next<0||next>100000) continue;
            if(place[next]==-1){
                q.push(next);
                place[next]=place[cur]+1;
            }
            if(next==k)
                return place[k];
        }
    }
    return place[k];
}

int main(){
    scanf("%d %d", &n, &k);
    fill_n(place, 100001, -1);
    printf("%d", bfs());
}
