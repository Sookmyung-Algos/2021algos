#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 300001
using namespace std;

int N,u,v;
vector <int> tree[300001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N;
    
    for (int i=0;i<N-1;i++){
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    int cnt_d=0;
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < tree[i].size(); j++) {
            int x = tree[i].size() - 1;
            int y = tree[tree[i][j]].size() - 1;
            cnt_d += x*y;
        }
    }
    cnt_d /=2;
    
    int cnt_g=0;
    for (int i=1;i<=N;i++){
        int size = tree[i].size();
        if (size>=3){
            cnt_g += size*(size-1)*(size-2)/6;
        }
    }
    if (cnt_d > cnt_g*3 ) cout << "D";
    else if (cnt_d == cnt_g*3) cout << "DUDUDUNGA";
    else cout << "G";
    
    return 0;
}
