#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

char arr[10][10];
int len[10];
int alpha[26];

bool desc(int a, int b){ return a > b; }

int main(void){
    int n;
    int cal;
    int result = 0;

    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%s", arr[i]);
        len[i] = strlen(arr[i]);
    }
    
    for(int i=0; i<n; i++){
        cal = 1;
        for(int j=len[i]-1; j>=0; j--){
            alpha[arr[i][j]-'A'] += cal;
            cal *= 10;
        }
    }
    
    sort(alpha, alpha+26, desc);
    
    for(int i=0; i<10; i++){
        result += alpha[i] * (9-i);
    }
    
    printf("%d\n", result);
}
