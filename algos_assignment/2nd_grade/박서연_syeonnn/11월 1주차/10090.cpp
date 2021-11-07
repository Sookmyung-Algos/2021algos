// 10090 (플5) Counting Inversions

#include <iostream>
#include <vector>
using namespace std;

vector<int>arr;
vector<int>temp;
int N;
long long ans = 0;

// 합병 정렬
void solve (int s, int e) {

    if (s == e) 
        return;

    int mid = (s + e) / 2;

    solve(s, mid);
    solve(mid + 1, e);

    int l = s;
    int r = mid + 1;
    long long cnt = 0;
    int index = 0;

    while (l <= mid || r <= e) {

        if (l <= mid && (r > e || arr[l] < arr[r])) {
            temp[index++] = arr[l++];
        }   // 왼쪽 배열부터
        else {
            temp[index++] = arr[r++];
            cnt += (mid - l + 1);
        }
    }

    for (int i = s; i <= e; i++) {
        arr[i] = temp[i - s];
    }

    ans += cnt;
}

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;

    arr.resize(N + 1);
    temp.resize(N + 1);

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    solve(0, N - 1);

    cout << ans;

    return 0;
}
