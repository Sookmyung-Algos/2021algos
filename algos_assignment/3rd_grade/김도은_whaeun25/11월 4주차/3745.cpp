#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> cache;

int main() {

    while (cin >> N) {
	    cache.clear();
	    for (int i = 1; i <= N; ++i) {
            
		    int cost;
            
		    cin >> cost;
            
		    if (cache.empty() || cache.back() < cost){
                cache.push_back(cost);
            } 
		    else {
			    int idx = lower_bound(cache.begin(), cache.end(), cost) - cache.begin();
			    cache[idx] = cost;
		    }
	    }
	    cout << cache.size() << '\n';
    }
}
