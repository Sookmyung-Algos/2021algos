#include <iostream>
#include <queue>
#include <tuple>
using namespace std;
typedef long long ll;

struct cmp {        //이동횟수 적은 순으로. 시간 적은 순으로
    bool operator()(tuple<int, int, int> a, tuple<int, int, int> b) {
        if (get<0>(a) == get<0>(b))
            return get<1>(a) > get<1>(b);
        return get<0>(a) > get<0>(b);
    }
};
priority_queue <tuple<ll, ll, ll>,vector<tuple<ll, ll, ll>>,cmp> q;
vector <pair<ll, ll>> v[1001];
ll n, m;
ll arr[1001];
ll dijk[1001][2];

void dist();

int main() {
    int x;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {       //회사
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> x;
            if (x != 0)
                v[i].push_back({ j,x });        //연결된 정류장, 시간
        }
    }

    dist();
}

void dist() {
    for (int i = 0; i < 1001; i++) {
        dijk[i][0] = 987654321;
        dijk[i][1] = 987654321;
    }
        
    dijk[0][0]=dijk[0][1] = 0;
    q.push({ 0,0,0 });        //환승횟수,시간,현재번호
    
    while (!q.empty()) {
        ll count = get<0>(q.top());
        ll time = get<1>(q.top());
        ll point = get<2>(q.top());
        q.pop();

        if (point == m) {
            cout << count << ' ' << time;
            return;
        }

        for (int i = 0; i < v[point].size(); i++) {
            ll next_p = v[point][i].first;
            ll next_t = v[point][i].second;

            //다음 점에 저장된 횐승횟수 < 현재점에 저장된 환승횟수(+1) 인 경우, 갈 필요 없음 <- 환승횟수가 무조건 작아야하니까
            if (arr[point]!=arr[next_p]){
                if (dijk[next_p][0] < dijk[point][0]+1)
                    continue;
            }
            else
                if (dijk[next_p][0] < dijk[point][0])
                    continue;

            if (dijk[next_p][1] > dijk[point][1] + next_t) {
                dijk[next_p][1] = dijk[point][1] + next_t;

                if (next_t > dijk[next_p][1])
                    continue;

                if (arr[point] == arr[next_p]) {
                    dijk[next_p][0] = count;
                    q.push({ count,dijk[next_p][1] ,next_p });
                }
                    
                else {
                    dijk[next_p][0] = count+1;
                    q.push({ count + 1,dijk[next_p][1] ,next_p });
                }
            }
        }
    }
}

