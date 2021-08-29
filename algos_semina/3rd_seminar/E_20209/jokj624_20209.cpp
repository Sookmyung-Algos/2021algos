//AC
//BOJ 20209 스트레이트 스위치 게임
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <map>
using namespace std;
typedef pair<int, int> pii;
vector<int> graph[9];
vector<int> num;
queue<vector<int>> q;
map<vector<int>, int> m;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int N, K;
    cin >> N >> K;
    for(int i=1; i<=N; i++) {
        int cu;
        cin >> cu;
        num.push_back(cu);
    }
    for(int i=0; i<K; i++) {
        int n;
        cin >> n;
        for(int j=0; j<n; j++) {
            int next;
            cin >> next;
            graph[i+1].push_back(next);
        }
    }
    int cnt = 0;
    bool ch = true;
    q.push(num);
    m[num] = 0;
    while(!q.empty()) {
        ch = true;
        vector<int> cur = q.front();
        q.pop(); 
        for(int temp : cur) {
            if (temp != cur[0]){
                ch = !ch;
                break;
            }
        } 
        if(ch){
            cnt = m[cur];
            break;
        }
        for(int i=1; i<=K; i++) {
            vector<int> next(N);
            copy(cur.begin(), cur.end(), next.begin());   
            for(int n : graph[i]) {
                next[n-1] = next[n-1] + i;
                if(next[n-1] > 4)    next[n-1] %= 5;
            }
            if(m.find(next) == m.end()) {
                m[next] = m[cur] + 1;
                q.push(next);
            }
        }
    }
    if(ch)   cout << cnt;
    else    cout << "-1";
    return 0;
}