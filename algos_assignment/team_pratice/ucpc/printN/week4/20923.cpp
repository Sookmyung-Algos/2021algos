#include <iostream>
#include <deque>

using namespace std;

deque<int> dq[2], G[2];

int N, M;

int ring_bell() {       //도도 0, 수연 1
    if (G[0].size() && G[0].front() == 5) return 0;
    if (G[1].size() && G[1].front() == 5) return 0;
    if (G[0].size() && G[1].size() && G[0].front() + G[1].front() == 5) return 1;
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> M;

    for (int i = 0; i < N; ++i) {
        int a, b; cin >> a >> b;
        dq[0].push_front(a);
        dq[1].push_front(b);
    }

    int turn = 0;

    for (int i = 0; i < M; ++i) {
        G[turn].push_front(dq[turn].front());
        dq[turn].pop_front();

        if (dq[turn].empty()) {
            cout << (turn ? "do" : "su") << '\n';
            return 0;
        }

        int r = ring_bell();

        if (r != -1) {
            
            int l = 1 - r; //종 치지 않은 사람

            while (G[l].size()) {
                dq[r].push_back(G[l].back());
                G[l].pop_back();
            }
            while (G[r].size()) {
                dq[r].push_back(G[r].back());
                G[r].pop_back();
            }
        }

        //차례 바꾸기
        turn = 1 - turn;
    }

    if (dq[0].size() == dq[1].size()) 
        cout << "dosu" << '\n';
    else if (dq[0].size() > dq[1].size()) 
        cout << "do" << '\n';
    else if (dq[0].size() < dq[1].size()) 
        cout << "su" << '\n';

    return 0;
}
