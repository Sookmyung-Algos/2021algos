#include<iostream>
#include<vector>
#include<memory.h>
#include<algorithm>
#include<math.h>
#include<queue>

using namespace std;
 
int n;
int arr[11];
int color[11];
int red, blue;
int redSum, blueSum;
int ans = 987987987;

vector <int> v[11];
 
queue<int> q;
bool check[11];
 
void bfs(int c) {
    while (!q.empty()) {
        int num = q.front();
        q.pop();
 
        if (c == 1) {
            red++;
            redSum += arr[num];
        }
        else {
            blue++;
            blueSum += arr[num];
        }
        
        for (int i = 0; i < v[num].size(); i++) {
            if (check[v[num][i]] == 0 && color[v[num][i]] == c) {
                check[v[num][i]] = 1;
                q.push(v[num][i]);
                
            }
        }
    }
}
 
void dfs(int cnt, int r, int b) {
    if (cnt == n+1) {
        
        red = 0; blue = 0;
        redSum = 0; blueSum = 0;
        memset(check, 0, sizeof(check));
        bool rf = false, bf = false;
        
        for (int i = 1; i <= n; i++) {
            if (rf == 1 && bf == 1) break;
            if (color[i] == 1 && check[i]==0 && rf==0) {
                rf = 1;
                check[i] = 1;
                q.push(i);
                bfs(1);
            }
            else if(color[i]==2 && check[i]==0 && bf==0){
                bf = 1;
                check[i] = 1;
                q.push(i);
                bfs(2);
            }
        }
        
        if (red != r || blue != b) return;
        ans = min(ans, abs(redSum - blueSum));
        return;
    }
 
    color[cnt] = 1;
    dfs(cnt + 1, r+1, b);
 
    color[cnt] = 2;
    dfs(cnt + 1, r, b+1);
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> arr[i];
 
    int a, b;
    for (int i = 1; i <= n; i++) {
        cin >> a;
        for (int j = 0; j < a; j++) {
            cin >> b;
            v[i].push_back(b);
        }
    }
 
    dfs(1, 0, 0);
    if (ans == 987987987) cout << -1 << "\n";
    else cout << ans << "\n";

    return 0;
}
