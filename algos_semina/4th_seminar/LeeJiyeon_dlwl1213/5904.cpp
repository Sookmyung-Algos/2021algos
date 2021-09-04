//규칙에 따라 재귀호출 해줘야 함

#include <iostream>

using namespace std;

int N;
int idx;

void moo(int n){
        if (n == 1){
                 if (idx + 1 == N){
                         cout << "m\n";
                         exit(0);
                 }

                 else if (idx + 2 == N || idx + 3 == N){
                         cout << "o\n";
                         exit(0);
                 }

                 idx += 3;
                 return;
        }

        moo(n - 1);
        if (idx + 1 == N){
                 cout << "m\n";
                 exit(0);
        }

        idx++;

        for (int i = 0; i <= n; i++){
                 if (idx + 1 == N){
                         cout << "o\n";
                         exit(0);
                 }
                 idx++;
        }
        moo(n - 1);
}


int main(void){
        ios_base::sync_with_stdio(0);
        cin.tie(0); cout.tie(0);
        cin >> N;

        moo(30); 
        return 0;
}
