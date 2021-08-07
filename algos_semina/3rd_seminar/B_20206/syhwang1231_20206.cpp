#include <iostream>
#include <vector>
using namespace std;

int rightCnt;
int leftCnt;
double a, b, c;
int x1, x2, Y1, y2;
vector<pair<int, int>> rect;  // 위험지역의 꼭짓점 좌표로 저장

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> a >> b >> c;  // 직선의 방정식
    cin >> x1 >> x2 >> Y1 >> y2;  // 위험 지역 좌표

    rect.push_back({ x1,Y1 });  // 꼭짓점 push
    rect.push_back({ x1,y2 });
    rect.push_back({ x2,Y1 });
    rect.push_back({ x2,y2 });

    //직선의 방정식을 부등식의 영역으로 보아서 위험지역 관통하는지 판단
    for (int i = 0; i < rect.size(); i++) {
        if (a * rect[i].first + b * rect[i].second >= -c)  // 직선 오른쪽에 존재
            rightCnt++;
        if (a * rect[i].first + b * rect[i].second <= -c)  // 직선 왼쪽에 존재
            leftCnt++;
    }

    if (leftCnt == 4 || rightCnt == 4)  // 모든 꼭짓점이 오른쪽 혹은 왼쪽에 존재해야 lucky
        cout << "Lucky";
    else
        cout << "Poor";
    return 0;
}
