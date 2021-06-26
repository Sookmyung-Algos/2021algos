#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	vector<int>pluV;
	vector<int>minV;
	int min = 0,plu=-1,zero=0;
	int n,num,ans=0;
	cin >> n;
	while (n--) {
		cin >> num;
		if (num < 0)
			minV.push_back(num);
		else
			pluV.push_back(num);
	}
	sort(pluV.begin(), pluV.end(),greater<>());
	sort(minV.begin(), minV.end());
	auto i = pluV.begin();
	while (i != pluV.end()) {
		if (*i == 1) ans++;
		else if (*i == 0) zero++;
		else {
			if (plu != -1) {
				ans += (*i) * plu;
				plu = -1;
			}
			else plu = *i;
		}
		i++;
	}
	i = minV.begin();
	while (i != minV.end()) {
		if (min != 0) {
			ans += (*i) * min;
			min = 0;
		}
		else min = *i;
		i++;
	}
	if (min != 0 && zero==0) ans+=min;
	if (plu != -1) ans += plu;
	cout << ans << endl;
	return 0;
}
