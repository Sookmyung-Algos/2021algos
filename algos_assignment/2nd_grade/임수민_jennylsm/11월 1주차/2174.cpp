#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <math.h>
#include <iostream>
#include <string>

using namespace std;

#define MAX 101

char Dir_state[4] = { 'N', 'E', 'S', 'W' };
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int A, B, N, M;
int arr[MAX][MAX];
vector <pair<pair<int, int>, int>> robot;

void Dir(int id, int cnt, char command) {
    if (command == 'L') {
        int check = robot[id - 1].second - (cnt % 4);
        robot[id - 1].second = check < 0 ? check + 4 : check;
    }
    else {
        int check = robot[id - 1].second + (cnt % 4);
        robot[id - 1].second = check > 3 ? check - 4 : check;
    }
}

int Solve(int id, int cnt) {
    for (int i = 0; i < cnt; i++) {
        int init_x = robot[id - 1].first.first;
        int init_y = robot[id - 1].first.second;
        int nx = robot[id - 1].first.first + dx[robot[id- 1].second];
        int ny = robot[id - 1].first.second + dy[robot[id - 1].second];
        int index = arr[nx][ny];
        if (nx >= 1 && nx <= B && ny >= 1 && ny <= A) {
            if (index == 0) {
                arr[init_x][init_y] = 0;
                arr[nx][ny] = id;
                robot[id - 1].first.first = nx, robot[id - 1].first.second = ny;
            }
            else
                return id * 100 + index;
        }
        else 
            return 1;
    }
    return 0;
}

int main() {
    cin >> A >> B >> N >> M;

    for (int i = 1; i <= N; i++) {
        int x, y, check;
        char direction;
        cin >> y >> x >> direction;

        for (int j = 0; j < 4; j++)
            if (Dir_state[j] == direction) {
                check = j; break;
            }
        robot.push_back(make_pair(make_pair(x, y), check));
        arr[x][y] = i;
    }

    for (int i = 0; i < M; i++) {
        int id, cnt; char command;
        cin >> id >> command >> cnt;

        if (command == 'F') {
            int result = Solve(id, cnt);
            if (result == 1) {
                cout << "Robot " << id << " crashes into the wall" << '\n';
                return 0;
            }
            else if (result > 100) {
                cout << "Robot " << result / 100 << " crashes into robot " << result % 100 << '\n';
                return 0;
            }
        }
        else {
            Dir(id, cnt, command);
        }
    }
    cout << "OK" << '\n';
    return 0;
}
