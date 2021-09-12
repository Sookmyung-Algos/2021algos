#include<cstdio>
#include<vector>
#include<math.h>
using namespace std;
int main() {
    int N;
    long long sum = 0;
    double ans = 0;
    scanf("%d", &N);
    vector<int> X;
    vector<int> Y;
    for (int i = 0; i < N; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        X.push_back(x);
        Y.push_back(y);
    }
    X.push_back(X.front());
    Y.push_back(Y.front());
    long long yy = 0;
    for (int i = 1; i < N; i++) {
        yy += Y[i] - Y[i - 1];
        sum += (X[i + 1] - X[i - 1]) * yy;  //좌표값을 벡터에 넣어 면적을 구했다
    }
    ans = sum / (double)2;
    printf("%.1lf\n", abs(ans));
}
