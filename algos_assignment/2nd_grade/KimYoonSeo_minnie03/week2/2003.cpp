#include <iostream> 
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;
int main(void) {
    ios::sync_with_stdio(false);
    LL N, M, answer = 0;
    cin >> N >> M;
    LL * A = (LL*)malloc(sizeof(LL)*(N + 1));
    for (LL n_idx = 1; n_idx <= N; n_idx++)
        cin >> A[n_idx];
 
    // left와 right 를 이동시키면서 합과 같은 녀석이 나오면 답++
    LL left = 1, right = 1, sum = 0;
    while (left <= right && right <= N + 1) {
        if (sum >= M) {
            if (sum == M) answer++;
            sum -= A[left++];
        }
        else {
            if (right == N + 1) break;
            sum += A[right++];
        }
    }
    cout << answer;
    return 0;
}
