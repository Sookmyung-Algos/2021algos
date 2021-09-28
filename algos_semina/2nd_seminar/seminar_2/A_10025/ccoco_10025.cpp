#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, const char * argv[]) {
    queue<int> q;
    int iceMax = 0;
    int iceTemp = 0;
    int posMax = 0;
    int n, k, tmp, pos;
    int ice[1000001] = {0, };
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &tmp, &pos);
        posMax = max(pos, posMax);
        ice[pos] = tmp;
    }
    int range = 2 * k + 1;
    for (int i = 0; i <= 1000000; i++) {
        if (q.size() == range) {
            iceTemp -= q.front();
            q.pop();
            q.push(ice[i]);
        } else if (q.size() < range){
            q.push(ice[i]);
        }
        iceTemp += ice[i];
        iceMax = max(iceMax, iceTemp);
    }
    printf("%d", iceMax);
    return 0;
}
