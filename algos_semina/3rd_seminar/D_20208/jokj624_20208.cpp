//AC
//BOJ 20208 진우의 민트초코 우유
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
using namespace std;
int  N, H, ans, homex, homey;
struct Mint {
    int x;
    int y;
    int check;
};
vector<Mint> v;
void solve(int x, int y, int M, int cnt) {
    if (cnt > ans) {
        if(abs(x - homex) + abs(y - homey) <= M)    ans = cnt;
        
    }
    if (M <= 0 || cnt == v.size()) return;
    for (Mint& mint : v) {
        int dist = abs(mint.x - x) + abs(mint.y - y);
        if (dist <= M && !mint.check) {
            mint.check = 1;
            solve(mint.x, mint.y, M + H - dist, cnt + 1);
            mint.check = 0;
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int M, temp;
    cin >> N >> M >> H;
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            cin >> temp;
            if(temp == 1) {
                homex = i;  homey = j;
            }
            else if(temp == 2) {
                v.push_back({i, j, 0});
            }
        }
    }
    solve(homex, homey, M, 0);
    cout << ans;
    return 0;
}
