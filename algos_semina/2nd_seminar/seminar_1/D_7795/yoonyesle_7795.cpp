#include <iostream>
#include <algorithm>
using namespace std;
int a[20001], ans, n;
void search(int num, int s, int e){
	while (s <= e)
    {
        int m = (s+e)/2;
        if (s==e){
        	if(a[s]>num) ans+=n-s;
        	return;
        }
        else if (a[m] <= num) s = m+1;
        else if (a[m] > num) e = m;
    }
}
int main(){
	int T, m, cur_search;
	scanf("%d", &T);
	while(T--){
		ans=0;
		scanf("%d%d", &n, &m);
		for(int i=0; i<n; i++)
			scanf("%d", &a[i]);
		sort(a, a+n);
		while(m--){
			scanf("%d", &cur_search);
			search(cur_search, 0, n-1);
		}
		printf("%d\n", ans);
	}
	return 0;
}
