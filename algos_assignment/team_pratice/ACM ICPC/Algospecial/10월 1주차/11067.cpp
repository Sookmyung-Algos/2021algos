#include <iostream>
#include <algorithm>
using namespace std;

bool cmp(pair<int,int> a, pair<int,int> b) {
    return a.second > b.second;
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int n, m, query[11];
        pair<int,int> point[100'002];
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) {
            scanf("%d%d", &point[i].first, &point[i].second);
        }
        scanf("%d", &m);
        for (int i = 0; i < m; ++i)
            scanf("%d", &query[i]);
        sort(point + 1, point + n + 1);
        bool dir = true;
        if (point[1].second == 0) dir = false;
        int start = 1, end = 1;
        while (true) {
            while (point[start].first == point[end].first && end <= n)
                ++end;
            if (dir)
                sort(point + start, point + end, cmp);
            if (end >= n)
                break;
            if (point[end].second != point[end - 1].second)
                dir = true;
            else
                dir = false;
            start = end;
        }
        for (int i = 0; i < m; ++i)
            printf("%d %d\n", point[query[i]].first, point[query[i]].second);
    }
}
