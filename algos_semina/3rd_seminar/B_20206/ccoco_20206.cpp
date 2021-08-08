#include <iostream>
#include <vector>
#include <set>

using namespace std;


int main(int argc, const char * argv[]) {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(false);
    
    int a, b, c;
    int x1, x2, y1, y2;
    cin >> a >> b >> c;
    cin >> x1 >> x2 >> y1 >> y2;
    
    int x[] = {x1, x1, x2, x2};
    int y[] = {y1, y2, y1, y2};
    
    set<bool> s;
    
    for (int i = 0; i < 4; i++) {
        if (a * x[i] + b * y[i] + c < 0)
            s.insert(false);
        else if (a * x[i] + b * y[i] + c == 0)
            continue;
        else s.insert(true);
    }
    
    if (s.size() == 1) cout << "Lucky" << '\n';
    else cout << "Poor" << '\n';
    
    return 0;
}
