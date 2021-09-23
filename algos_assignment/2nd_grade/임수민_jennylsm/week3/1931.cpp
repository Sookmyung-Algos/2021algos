#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
    int num;
    int cnt = 0;
    vector<pair<int, int> > v;
    cin >> num;
    for (int i = 0; i < num; i++) {
        int start, end;
        cin >> start >> end;
        v.push_back(make_pair(end, start));  //시작시간과 끝나는 시간을 v에 넣어줌
    }
    sort(v.begin(), v.end());  //오름차순 정렬
    int t = 0;
    for (int i = 0; i < num; i++) {
        int start = v[i].second;
        int end = v[i].first;

        if (start >= t) {
            t = end;
            cnt++;  //가능한 개수에 1을 더해줌
        }
    }
    cout << cnt << '\n';
}
