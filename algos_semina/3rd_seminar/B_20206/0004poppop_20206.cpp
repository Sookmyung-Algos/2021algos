#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int a, b, c;
int up = 0, down = 0;   // 위험지역 통과 여부 확인을 위한 변수

int main() {
    cin >> a >> b >> c;

    int x1, x2, y1, y2;
    vector<pair<int, int>> cmp; // 호민이의 이동경로와 위험지역 위치 비교를 위해 벡터에 점들의 좌표 저장

    cin >> x1 >> x2 >> y1 >> y2;

    cmp.push_back({ x1,y1 });
    cmp.push_back({ x1,y2 });
    cmp.push_back({ x2,y1 });
    cmp.push_back({ x2,y2 });

    for (int i = 0; i < 4; i++) {
        if (a * cmp[i].first + b * cmp[i].second + c > 0)
            up++;   // i번째 좌표보다 위에 있음
        else if (a * cmp[i].first + b * cmp[i].second + c < 0)
            down++; // i번째 좌표보다 아래에 있음
    }
    if (up > 0 && down > 0)
        cout << "Poor" << '\n';
    else
        cout << "Lucky" << '\n';


    return 0;
}
