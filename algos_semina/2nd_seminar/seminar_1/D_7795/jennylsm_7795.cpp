#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int T;
    cin >> T;

    while (T--) {
        int N, M;
        cin >> N >> M;

        int A[20000];
        int B[20000];

        for (int i = 0; i < N; i++) cin >> A[i];
        for (int i = 0; i < M; i++) cin >> B[i];

        sort(A, A + N);
        sort(B, B + M);

        int ans = 0;
        for (int i = 0; i < N; i++) {
            int tmp = A[i];
            if (tmp > B[M - 1]) {
                ans += M; continue;
            }
            if (tmp <= B[0]) continue;

            int left = 0; int right = M - 1;
            int mid = (left + right) / 2;

            while (tmp > B[mid]) mid = (right + mid + 1) / 2;
            // escape when B[mid]>tmp
            while (tmp <= B[mid]) mid--;

            ans += (mid + 1);
        }

        cout << ans << '\n';
    }

}
