#include <bits/stdc++.h>

using namespace std;

int N, Cut;
vector <int> adj[55];

int DFS(int curr){
	int ret = 1;
	int child = 0;
	for (auto ch: adj[curr]){
		if(ch==Cut) continue;
		child += DFS(ch);
	}
	if(child) return child;
	else return ret;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    int Root;
    for (int i = 0; i < N; ++i) {
	    int parent;
	    cin >> parent;
	    if(parent==-1) Root=i;
	    else adj[parent].push_back(i);
    }
    cin >> Cut;

    if(Root!=Cut) cout << DFS(Root) << '\n';
    else cout << 0 << '\n';

    return 0;
} 	
