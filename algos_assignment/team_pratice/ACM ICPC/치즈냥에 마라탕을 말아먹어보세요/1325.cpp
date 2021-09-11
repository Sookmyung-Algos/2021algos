#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

int main(){
    int n,m;
    int count;
    int max = 0;
    cin >> n >> m;

    vector<int> graph[n+1];
    int max_int[n+1] = {0};

    for(int i=0; i<m; i++){
        int u,v;
        cin >> u >> v;
        graph[v].push_back(u);

    }
    for(int i=1; i<=n; i++){
        count = 0;
        for (int v : graph[i]) {
            count++;
            for(int w : graph[v]){
                count++;
            }
		
	    }
        max_int[i] = count;
        if(count > max) {
            max = count;
        }
    }

    for(int i=1; i<=n; i++){
        if(max_int[i] == max){
            cout << i << ' ';
        }
    }
    
}
