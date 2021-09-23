#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

struct person{
    int d, h, l;
};
typedef struct person person;
struct compare{
    bool operator()(person &p1, person &p2){
        if(p1.d==p2.d){
            if(p1.h==p2.h){
                return p1.l>p2.l;
            }
            return p1.h<p2.h;
        }
        return p1.d<p2.d;
    }
};

int n, m, k, pos[2];
vector<person> lines[100000];
int idx[100000]={0, };

int main(){
    scanf("%d %d %d", &n, &m, &k);
    person p;
    for(int i=0;i<n;i++){
        scanf("%d %d", &p.d, &p.h);
        p.l=i%m;
        lines[i%m].push_back(p);
        if(i==k){
            pos[0]=i%m;
            pos[1]=lines[i%m].size()-1;
        }
    }
    priority_queue<person,vector<person>,compare> pq;
    for(int i=0;i<m;i++){
        if(i>=n) break;
        pq.push(lines[i][idx[i]]);
        idx[i]+=1;
    }
    int cnt=0;
    while(!pq.empty()){
        p=pq.top(); pq.pop();
        if(p.l==pos[0]&&idx[p.l]-1==pos[1])
            break;
        cnt++;
        if(idx[p.l]<lines[p.l].size()){
            pq.push(lines[p.l][idx[p.l]]);
            idx[p.l]+=1;
        }
    }
    printf("%d", cnt);
}
