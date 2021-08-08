#include <iostream>
#include <vector>

using namespace std;

int main(int argc, const char * argv[]) {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(false);
    
    int N, K;
    cin >> N >> K;

    for (int a = 0; a < N; a++) {
        vector<int> iv;
        for (int i = 0; i < N; i++) {
            int tmp;
            cin >> tmp;
            iv.push_back(tmp);
        }
        for (int oi = 0; oi < K; oi++) {
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < K; j++) {
                    cout << iv[i] << ' ';
                }
            }
            cout << '\n';
        }
    }
    return 0;
}
