// 1043 (골드4) 거짓말

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int people[51]; // 전체 사람
int know_people[51];    // 진실을 아는 사람
int party[51][51];  // 파티에 온 사람
int n, m;   // 전체 사람 수, 파티 수
int cnt = 0;    // 과장된 이야기를 할 수 있는 파티의 개수의 최댓값
int whoknows_num, whocomes_num;    // 진실을 아는 사람 수, 파티에 온 사람 수

int Find(int x) {
    if (people[x] == x)
        return x;
    else
        return x = Find(people[x]);
}   // x가 속한 집합 찾기

void Union(int x, int y) {
    x = Find(x);
    y = Find(y);
    people[y] = x;
}   // x가 속한 집합과 y가 속한 집합 합치기, y의 집합을 x의 집합으로 변경

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;  
    cin>> whoknows_num;

    for (int i = 1; i <= n; i++) 
        people[i] = i;  // 전체 사람들 번호 부여

    for (int i = 0; i < whoknows_num; i++)
        cin >> know_people[i];

    for (int i = 0; i < m;i++) {    
        cin >> whocomes_num;
        for (int j = 0; j < whocomes_num; j++) {
            if (j >= 1) {
                cin >> party[i][j];
                Union(party[i][0], party[i][j]);    // 같은 파티에 온 사람들끼리 묶음
            }
            else {
                cin >> party[i][0]; // i번 파티에 온 첫 번째 사람
            }
        }  
    }

    for (int i = 0; i < m;i++) {    // 파티에 온 사람들 중
        bool tellLie = true;
        for (int j = 0; j < whoknows_num; j++) {    // 진실을 아는 사람들에 대해
            if (Find(party[i][0]) == Find(know_people[j])) {    // 진실을 아는 사람이 있다면
                tellLie = false;    // 과장하면 안됨
                break;
            }
        }
        if (tellLie)
            cnt++;
    }

    cout << cnt << '\n';

    return 0;
}
