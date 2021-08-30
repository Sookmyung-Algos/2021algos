#include <cstdio>
#include <vector>
using namespace std;

vector<int> map[13];

int main(){
    int i;
    for(i=1;i<=12;i++){
        int x,y;
        scanf("%d %d", &x, &y);
        map[x].push_back(y);
        map[y].push_back(x);
    }
    for(i=1;i<=12;i++){
        if(map[i].size()!=3)
            continue;
        bool flag1=false, flag2=false;
        for(int next:map[i]){
            if(map[next].size()==1)
                flag1=true;
            if(map[next].size()==2)
                flag2=true;
        }
        if(flag1&&flag2)
            break;
    }
    printf("%d", i);
}
