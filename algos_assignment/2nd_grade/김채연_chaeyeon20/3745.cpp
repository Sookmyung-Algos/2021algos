#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> lis;
int main() {
    int N;
    while (scanf("%d", &N) != EOF) {
        lis.clear();
        for (int i = 0; i < N; i++) {
            int tmp, ans;
            scanf("%d", &tmp);
            if (lis.empty() || lis[lis.size() - 1] < tmp) lis.push_back(tmp);
            else {
                int L = 0, R = lis.size() - 1;
                while (L <= R) {
                    int mid = (L + R) / 2;
                    if (lis[mid] >= tmp) {
                        ans = mid;
                        R = mid - 1;
                    }
                    else L = mid + 1;
                }
                lis[ans] = tmp;
            }
        }
        printf("%d\n", lis.size());
    }
    return 0;
}


