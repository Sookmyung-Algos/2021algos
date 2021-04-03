#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>

using namespace std;

int main(int argc, const char * argv[]) {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(false);
    
    int n, tmp;
    cin >> n;
    unordered_map<int, int> map;
    int arr[n];
    set<int> s;
    
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        s.insert(tmp);
        arr[i] = tmp;
    }
    
    set<int>::iterator iter;
    int index = 0;
    for (iter = s.begin(); iter != s.end(); ++iter) {
        map.insert(make_pair((int)*iter, index++));
    }
    
    for (int x: arr) {
        cout << map[x] << ' ';
    }
    return 0;
}
