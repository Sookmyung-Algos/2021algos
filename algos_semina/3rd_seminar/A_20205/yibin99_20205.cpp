#include <cstdio>
using namespace std;

int n, k;
int pixel[11][11];

int main(){
    scanf("%d %d", &n, &k);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            scanf("%d", &pixel[i][j]);
    }
    for(int i=0;i<n;i++){
        for(int l=0;l<k;l++){
            for(int j=0;j<n;j++){
                for(int m=0;m<k;m++){
                    printf("%d ", pixel[i][j]);
                }
            }
            printf("\n");
        }
    }
}
