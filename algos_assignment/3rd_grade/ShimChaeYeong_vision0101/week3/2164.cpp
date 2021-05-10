#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    queue<int> Q;
    
    cin >> n;

    for(int i=1; i<=n; i++){
        Q.push(i);
    }

    while(Q.size() != 1){
        Q.pop();
        int front = Q.front();
        Q.pop();
        Q.push(front);
    }
    cout << Q.front();
}
