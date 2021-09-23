#include <iostream>
#include <algorithm>
#include <vector>
#pragma warning(disable : 4996)

using namespace std;

int main() {

    int gong_u[200000];
    int N, C;
    cin >> N >> C;

    for (int i = 0; i < N; i++) {
        cin >> gong_u[i];
    }

    sort(gong_u, gong_u + N);   // 좌표 순서대로 정렬 
    
    int left = gong_u[0];   // 가능한 최소 거리
    int right = gong_u[N-1]- gong_u[0]; // 가능한 최대 거리
    int ans = 0;

    while (left <= right) {
        int mid = (left + right) / 2;
        int start = 0;
        int cnt = 1;

        for (int i = 1; i < N; i++) {
            if ( gong_u[i]-gong_u[start] >=mid) {
                start = i;
                cnt++;
            }   
        }   // 현재 위치와 직전 설치한 공유기의 위치의 간격이 mid 보다 크면 공유기 설치

        if (cnt >= C) {
            ans = mid;
            left = mid + 1;
        }   //  설치된 공유기 수가 계획보다 많다면 간격을 넓혀 공유기 수 줄임
        else {
            right = mid - 1;
        }   // 설치된 공유기 수가 계획보다 적다면 간격을 좁혀 공유기 수 늘림
    }   // 이분 탐색을 통해 간격 설정

    cout << ans;
    return 0;
}
