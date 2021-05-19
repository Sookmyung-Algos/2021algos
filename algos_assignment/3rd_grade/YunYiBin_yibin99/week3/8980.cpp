#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class D{
public:
    int from;
    int to;
    int cnt;
    D(int from, int to, int cnt){
        this->from=from;
        this->to=to;
        this->cnt=cnt;
    }
};
bool compare(D a, D b){
    if(a.to==b.to)
        return a.from<b.from;
    return a.to<b.to;
}
int main(){
    int n, c, m;
    int from, to, cnt;
    int minc, d, sum=0;
    vector<D> deliv;

    cin  >> n >> c >> m;
    for(int i=0;i<m;i++){
        cin >> from >> to >> cnt;
        deliv.push_back(D(from, to, cnt));
    }
    vector<int> capa(n+1, c);
    sort(deliv.begin(), deliv.end(), compare);
    for(int i=0;i<m;i++){
        minc=capa[deliv[i].from];
        for(int j=deliv[i].from;j<deliv[i].to;j++){
            if(capa[j]<minc) minc=capa[j];
        }
        d=min(minc, deliv[i].cnt);
        sum+=d;
        for(int j=deliv[i].from;j<deliv[i].to;j++)
            capa[j]-=d;
    }
    cout << sum;
}
