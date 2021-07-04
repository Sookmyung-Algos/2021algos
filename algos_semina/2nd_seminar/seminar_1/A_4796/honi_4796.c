#include <stdio.h>

main(){
    int l,p,v;
    int count=1, day,sum;
    
    while (1){
        scanf("%d %d %d",&l,&p,&v);
        if (l==0&&p==0&&v==0)
            break;
        
        sum=0;
        day=v%p;
        if (day<l)
            sum=(v/p)*l+day;
        else
            sum=(v/p)*l+l;
        
        printf("Case %d: %d\n",count, sum);
        count++;
    }
    return 0;
}
