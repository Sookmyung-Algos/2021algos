#include <iostream>
#include <vector>
using namespace std;

int n;
vector<vector<int>> slates;
vector<int> v;

/*
  1. 더 자를지 말지 결정
  2. 한 조각의 조건을 만족하는 경우 혹은 어떻게 해도 한 조각이 안되는 경우 못 자름
  3. 더 자를 경우 가로, 세로 바꿔서 자르기
    3-1. 불순물 찾기
    3-2. 불순물의 라인(가로 혹은 세로)에 보석이 있는지 확인
    3-3. 보석이 있으면 다음 불순물 찾고, 없으면 자르기
*/

// 왼쪽 상단 (r1,c1), 오른쪽 하단 (r2, c2)
int slice(int r1, int c1, int r2, int c2, bool isHorizontal) {
    if (r1 < 0 || r2 > n || c1 < 0 || c2 > n)
        return 0;
    // 더 자를 필요가 있는지 확인
    int impurities = 0, jewels = 0;
    for (int i = r1; i < r2; i++) {
        for (int j = c1; j < c2; j++) {
            if (slates[i][j] == 1)
                impurities++;
            else if (slates[i][j] == 2)
                jewels++;
        }
    }
    //cout << jewels << ' ' << impurities << "\n";

    if (impurities == 0 && jewels == 1)  // 한 조각의 조건(불순물 0개, 보석 1개) 만족
        return 1;
    else if (impurities == 0 && jewels >= 2)  // 불순물은 0개인데 보석이 1개보다 많음
        return 0;
    else if (impurities >= 1 && jewels == 1)  // 보석은 1개지만 불순물이 0개보다 많음
        return 0;
    else if (jewels == 0)  // 보석이 없으면 
        return 0;

    // 더 자르기
    int result = 0;
    for (int i = r1; i < r2; i++) {
        for (int j = c1; j < c2; j++) {
            if (slates[i][j] == 1) {  // 불순물 찾음
                if (isHorizontal) {  // 이번엔 세로로 자를 차례
                    bool hasJewel = false;
                    for (int k = r1; k < r2; k++) {
                        if (slates[k][j] == 2) {  // 자를 세로에 보석이 있는지 확인
                            hasJewel = true;
                            break;
                        }
                    }
                    if (!hasJewel) {
                        result += slice(r1, c1, r2, j, !isHorizontal) * slice(r1, j + 1, r2, c2, !isHorizontal);  // 왼,오 순서(경우의 수이므로 곱하기)
                    }
                }
                else {  // 아니라면 이번엔 가로로 자를 차례
                    bool hasJewel = false;
                    for (int k = c1; k < c2; k++) {
                        if (slates[i][k] == 2) {  // 자를 가로에 보석이 있는지 확인
                            hasJewel = true;
                            break;
                        }
                    }
                    if (!hasJewel)
                        result += slice(r1, c1, i, c2, !isHorizontal) * slice(i + 1, c1, r2, c2, !isHorizontal);  // 위*아래
                }
            }
        }
    }
    return result;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
        slates.push_back(v);

    int info;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> info;
            slates[i].push_back(info);
        }
    }

    int result1 = slice(0, 0, n, n, true);  // 처음을 가로로 자르는 경우, 세로로 자르는 경우 나눠서
    int result2 = slice(0, 0, n, n, false);
    if (result1 + result2 == 0)
        cout << -1;
    else
        cout << result1 + result2;

    return 0;
}
