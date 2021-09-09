#include <iostream>

using namespace std;

int N, M;
int arr[101][101];
long long Max = 0;

long long getSum(int sx, int sy, int ex, int ey) {
    long long sum = 0;

    for (int i = sy; i <= ey; i++) {
        for (int j = sx; j <= ex; j++) {
            sum += arr[i][j];
        }
    }

    return sum;
}

int main(void) {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            char tmp;
            cin >> tmp;
            arr[i][j] = tmp - '0';
        }
    }

    for (int i = 0; i < M - 2; i++) {
        for (int j = i + 1; j < M - 1; j++) {
            long long a = getSum(0, 0, i, N - 1);
            long long b = getSum(i + 1, 0, j, N - 1);
            long long c = getSum(j + 1, 0, M - 1, N - 1);
            if (Max < a * b * c)
                Max = a * b * c;
        }
    }

    for (int i = 0; i < N - 2; i++) {
        for (int j = i + 1; j < N - 1; j++) {
            long long a = getSum(0, 0, M - 1, i);
            long long b = getSum(0, i + 1, M - 1, j);
            long long c = getSum(0, j + 1, M - 1, N - 1);
            if (Max < a * b * c)
                Max = a * b * c;
        }
    }

    for (int i = 0; i < M - 1; i++) {
        for (int j = 0; j < N - 1; j++) {
            long long a = getSum(0, 0, i, N - 1);
            long long b = getSum(i + 1, 0, M - 1, j);
            long long c = getSum(i + 1, j + 1, M - 1, N - 1);
            if (Max < a* b* c)
                Max = a * b * c;
        }
    }

    for (int i = M - 1; i > 0; i--) {
        for (int j = 0; j < N - 1; j++) {
            long long a = getSum(i, 0, M - 1, N - 1);
            long long b = getSum(0, 0, i - 1, j);
            long long c = getSum(0, j + 1, i - 1, N - 1);
            if (Max < a * b * c)
                Max = a * b * c;
        }
    }

    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < M - 1; j++) {
            long long a = getSum(0, 0, M - 1, i);
            long long b = getSum(0, i + 1, j, N - 1);
            long long c = getSum(j + 1, i + 1, M - 1, N - 1);
            if (Max < a* b* c)
                Max = a * b * c;
        }
    }

    for (int i = N - 1; i > 0; i--) {
        for (int j = 0; j < M - 1; j++) {
            long long a = getSum(0, i, M - 1, N - 1);
            long long b = getSum(0, 0, j, i - 1);
            long long c = getSum(j + 1, 0, M - 1, i - 1);
            if (Max < a * b * c)
                Max = a * b * c;
        }
    }
    cout << Max << '\n';
    return 0;
}
