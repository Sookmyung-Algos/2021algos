#include<iostream>
using namespace std;
 
char DB[][6]=
{ "  *  ",
  " * * ",
  "*****" }; // 만들고 시작하기
char MAP[3500][6500];
 
void check(int n, int y, int x){
    if (n == 1){
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 5; j++)
                MAP[y + i][x + j] = DB[i][j];
        return;
    }
    check(n / 2, y, x + 3 * n / 2);
    check(n / 2, y + 3 * n / 2, x);
    check(n / 2, y + 3 * n / 2, x + 3 * n);
}
 
int main(){
    int n; cin >> n;
    check(n / 3, 0, 0);
    for(int i=0;i<n;i++,puts(""))
        for(int j=0;j<2*n-1;j++){
        	char c =MAP[i][j] == '*'?'*':' ';
        	cout << c;
        }
    return 0;
}
