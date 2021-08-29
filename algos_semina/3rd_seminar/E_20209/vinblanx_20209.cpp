#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

int N, K;
vector <int> sch[8];

bool Same(vector<int>& v){
    int n = v[0];
    for(int i : v) if(n != i)
        return false;
    return true;
}

vector<int> press(vector<int>& cube, int n){
    vector<int> ret = cube;

    for(int i : sch[n]){
        ret[i-1] += n + 1;
        ret[i-1] %= 5;
    }
    return ret;
}

int bfs(vector<int>& init){
    map <vector<int>,int> m;
    queue <vector<int>> q;

    m[init] = 0;
    q.push(init);

    while(!q.empty()){
        vector<int> cur = q.front();
        q.pop();

        int curDist = m[cur];

        if(Same(cur))
            return curDist;

        for(int i=0;i<K;i++){
            vector <int> next = press(cur, i);
            if(m.find(next) == m.end()){
                m[next] = curDist + 1;
                q.push(next);
            }
        }
    }
    return -1;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N >> K;

    vector <int> cube(N);
    for(int& i : cube) cin >> i;

    for(int i = 0; i < K; i++){
        int n;
        cin >> n;
        sch[i] = vector <int> (n);
        for(int& num : sch[i]) cin >> num;
    }

    cout << bfs(cube);

    return 0;
}
