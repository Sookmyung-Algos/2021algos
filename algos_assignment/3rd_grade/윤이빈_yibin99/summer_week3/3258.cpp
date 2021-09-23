#include <cstdio>
#include <algorithm>
using namespace std;

int n, z, m;
bool field[1001];

int main(){
    scanf("%d %d %d", &n, &z, &m);
    int tmp, k;
    for(int i=0;i<m;i++){
        scanf("%d", &tmp);
        field[tmp]=true;
    }
    for(k=1;k<1000;k++){
        int i=1;
        bool check[1001];
        copy(field, field+1000, check);
        while(i!=z){
            if(check[i])
                break;
            else{
                check[i]=true;
                i+=k;
                if(i>n) i-=n;
            }
        }
        if(i==z)
            break;
    }
    printf("%d", k);
}
