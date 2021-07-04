#include <fstream>
#include<iostream>
#include <string.h>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;


bool ch[101];
bool check = false;

void dfs(int sx, int sy, int ex, int ey, vector<pair<int, int> >conv) {
    
    if ((abs(sx - ex) + abs(sy - ey)) <= 1000) {
        check = true;
        return;
    }
    for (int i = 0; i < conv.size(); i++) {
        if ((abs(sx - conv[i].first) + abs(sy - conv[i].second)) <= 1000 && !ch[i]) {
           
            ch[i] = true;
            dfs(conv[i].first, conv[i].second, ex, ey, conv);
        }

    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);


    int t, n, x, y, sx, sy, ex, ey;
    cin >> t;

    while (t-- > 0) {
        cin >> n;
        cin >> sx >> sy;
        vector <pair<int, int> >conv;

        for (int i = 0; i < n; i++) {
            cin >> x >> y;
            conv.push_back(make_pair(x, y));
        }

        cin >> ex >> ey;
        check = false;
        memset(ch, false, sizeof(ch));
        dfs(sx, sy, ex, ey, conv);
        if (check) cout << "happy" << "\n";
        else cout << "sad" << "\n";

    }

    return 0;
}
