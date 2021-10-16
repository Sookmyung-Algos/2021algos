#include<stdio.h>
#include<queue>
#include<vector>
#include<string.h>

using namespace std;

int need, w, h;
char map[1001][1001];
int visit[1001][1001];

queue<pair<int, int> > fire;
queue<pair<int, int> > people;

int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };

void bfs() {
    while (!people.empty()) {
        need++;
        int firesize = fire.size();

        for (int i = 0; i < firesize; i++) {
            pair<int, int> now_fire = fire.front();
            int now_x = now_fire.first; int now_y = now_fire.second;
            fire.pop();

            for (int i = 0; i < 4; i++) {
                int future_x = now_x + dx[i];
                int future_y = now_y + dy[i];

                if (future_x >= 0 && future_y >= 0 && future_x < w && future_y < h) {
                    if (map[future_y][future_x] != '#' && map[future_y][future_x] != '*') {
                        map[future_y][future_x] = '*';
                        fire.push(make_pair(future_x, future_y));
                    }
                }
            }
        }
        
        int peoplesize = people.size();
        for (int i = 0; i < peoplesize; i++) {
            pair<int, int> now_people = people.front();
            int nowx_people = now_people.first; int nowy_people = now_people.second;
            people.pop();

            for (int i = 0; i < 4; i++) {
                int futurep_x = nowx_people + dx[i];
                int futurep_y = nowy_people + dy[i];
                if (futurep_x >= w || futurep_x < 0 || futurep_y < 0 || futurep_y >= h) {
                    return;
                }

                if (futurep_x >= 0 && futurep_y >= 0 && futurep_x < w && futurep_y < h && visit[futurep_y][futurep_x] == 0) {
                    if (map[futurep_y][futurep_x] != '#' && map[futurep_y][futurep_x] != '*') {
                        visit[futurep_y][futurep_x] = 1;
                        people.push(make_pair(futurep_x, futurep_y));
                    }
                }
            }
        }
    }
    need = -1;
}

int main() {
    int num;
    scanf("%d", &num);

    for (int i = 0; i < num; i++) {
        scanf("%d %d", &w, &h);

        for (int i = 0; i < h; i++) {
            scanf("%s", map[i]);

            for (int j = 0; j < w; j++) {
                if (map[i][j] == '@') {
                    people.push(make_pair(j, i));
                    visit[i][j] = 1;
                }
                else if (map[i][j] == '*') {
                    fire.push(make_pair(j, i));
                }
            }
        }

        bfs();

        if (need == -1)
            printf("IMPOSSIBLE\n");
        else
            printf("%d\n", need);
        memset(visit, 0, sizeof(visit));
        need = 0;
        while (!fire.empty())
            fire.pop();
        while (!people.empty())
            people.pop();
    }
}
