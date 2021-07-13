#include <iostream>
using namespace std;

int board[101][101];
int dir[10001];
int m[101][101];

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, k, x, y, l, z, head_dir, tail_dir;
    long long head_time, tail_time;
    pair<int, int> head, tmp, tail;
    char c;

    cin >> n >> k;
    for (int i = 0; i < k; i++) {
        cin >> x >> y;
        board[x - 1][y - 1] = 1;
    }

    cin >> l;

    for (int i = 0; i < l; i++) {
        cin >> z >> c;
        dir[z] = c;
    }

    m[0][0] = 1;

    head = { 0, 0 }, tmp = { 0, 0 }, tail = { 0, 0 };
    head_time = 0, tail_time = 0;
    head_dir = 0, tail_dir = 0;

    while (1) {
        if (dir[head_time]) {
            if (dir[head_time] == 'D') head_dir = (head_dir + 1) % 4;
            else head_dir = (head_dir + 3) % 4;
        }

        tmp.first = head.first + dx[head_dir];
        tmp.second = head.second + dy[head_dir];

        if (0 <= tmp.first && tmp.first < n && 0 <= tmp.second && tmp.second < n
            && !m[tmp.first][tmp.second]) {
            head.first += dx[head_dir];
            head.second += dy[head_dir];
            m[head.first][head.second] = 1; 
            head_time++;

            if (!board[head.first][head.second]) {
                m[tail.first][tail.second] = 0;
                if (dir[tail_time]) {
                    if (dir[tail_time] == 'D') tail_dir = (tail_dir + 1) % 4;
                    else tail_dir = (tail_dir + 3) % 4;
                }
                tail.first += dx[tail_dir];
                tail.second += dy[tail_dir];
                tail_time++;
            }
            else board[head.first][head.second] = 0;
        }
        else break;
    }

    cout << head_time + 1 << '\n';

    return 0;
}
