#include <iostream>
#define MAX 200001
using namespace std;

int edge[MAX];
int main(){
    int n; cin >> n;
    for(int i=0; i<n-1; ++i){
        int s,e; cin >> s >> e;
        edge[s]++; edge[e]++;
    }
    
    int cnt=0;
    for(int i=0; i<n; ++i){
        if (edge[i]==1)
            ++cnt;
    }
    cout << (cnt+1)/2;
    
    return 0;
}
