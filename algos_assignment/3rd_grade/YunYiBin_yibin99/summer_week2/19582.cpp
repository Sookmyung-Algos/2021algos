#include <cstdio>
using namespace std;

int n;
int x, p, maxp;
long long int sum;
bool flag=true;

int main(){
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        scanf("%d %d", &x, &p);
        if(sum<=x){
            sum+=p;
            maxp=(p>maxp)?p:maxp;
        }
        else{
            if(flag==false){
                printf("Zzz");
                return 0;
            }
            flag=false;
            if(p<maxp){
                sum-=maxp;
                if(sum<=x)
                    sum+=p;
                else
                    sum+=maxp;
            }
        }
    }
    printf("Kkeo-eok");        
}
