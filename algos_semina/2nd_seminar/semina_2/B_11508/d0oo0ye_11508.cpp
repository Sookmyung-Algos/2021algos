#include <iostream>
#include <queue>

using namespace std;

int main() {
	int n;
	cin >> n;
	priority_queue<int> price;
  
	for (int i = 0; i < n; i++) {
		int p;
    
		cin >> p;
		price.push(p);
	}

	int min_price = 0;
	for (int i = 1; !price.empty(); i++) {
		if (i % 3 == 0) { 
			price.pop();
            
			continue;
		}
		
		min_price += price.top();
		price.pop();
	}
    
	cout << min_price << endl;
}
