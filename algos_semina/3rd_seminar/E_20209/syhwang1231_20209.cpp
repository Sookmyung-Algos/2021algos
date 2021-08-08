#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;

int n, k;  // n:큐브, k: 스위치
vector<vector<int>> swtch;  // 스위치

bool isAllSame(vector<int> v) {  // 종결 조건 만족하는지 확인
    if (*max_element(v.begin() + 1, v.end()) == *min_element(v.begin() + 1, v.end()))
        return true;  // 최댓값과 최솟값이 같으면 모든 원소가 같음
    return false;
}

vector<int> pressSwtch(vector<int> v, int index) {
    vector<int> ret = v;
    vector<int> cList = swtch[index];  // index번째 스위치와 연결된 큐브의 리스트
    for (int i = 0; i < cList.size(); i++) {
        ret[cList[i]] += index;
        ret[cList[i]] %= 5;  // 5넘는 경우도 나머지 연산으로 처리
    }
    return ret;
}

int bfs(vector<int>& cube) {
    map<vector<int>, int> cubeMap;  // (큐브 값 벡터, 그때의 스위치 누른 횟수)의 쌍
    queue<vector<int>> q;
    cubeMap[cube] = 0;  // 처음 bfs 실행 시 cube에 대해 스위치 누른 횟수는 0
    q.push(cube);

    while (!q.empty()) {  // bfs 과정
        vector<int> curCube = q.front();
        q.pop();

        int curCnt = cubeMap[curCube];

        if (isAllSame(curCube))  // 종결 조건 만족하면 누른 횟수 return
            return curCnt;

        for (int i = 1; i < k + 1; i++) {  // 스위치 하나씩 누른 결과를 q에 push
            vector<int> next = pressSwtch(curCube, i);
            if (cubeMap.find(next) == cubeMap.end()) {  // cubeMap에서 next와 같은 키 존재하지 않는다면
                q.push(next);
                cubeMap[next] = curCnt + 1;  // 누른 횟수 1 증가 후 저장
            }
        }
    }
    return -1;  // while문에서 끝내지 못한다면 조건 만족 X -> -1 return
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> k;
    vector<int> cube(n + 1);
    swtch.resize(k + 1);
    for (int i = 1; i <= n; i++)  // 1번인덱스부터 저장하기
        cin >> cube[i];

    int tmp;
    for (int i = 0; i < k; i++) {
        cin >> tmp;
        vector<int> v(tmp);
        for (int j = 0; j < tmp; j++)
            cin >> v[j];
        swtch[i + 1] = v;  // 1번 인덱스부터 저장(1번 스위치)

    }

    int answer = bfs(cube);
    cout << answer;
    return 0;
}
