#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(false);
    
    int N;
    int v[1000000];
    cin>>N;
    for (int i=0;i<N;i++)
        cin>>v[i];
    sort(v,v+N);
    for (int i=0;i<N;i++)
        cout<<v[i]<<'\n';
}
