#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int>w;
vector<int>k;

int main() {

	for (int i = 0; i < 10; i++){
        int a;
        
        cin >> a;
        
        w.push_back(a);
    }
    
    for (int i = 0; i < 10; i++){
        int a;
        
        cin >> a;
        
        k.push_back(a);
    }

	sort(w.begin(), w.end());
	sort(k.begin(), k.end());

	cout << w[7] + w[8] + w[9] << " " << k[7] + k[8] + k[9];	

}
