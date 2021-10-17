#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    int N;
    double M;
    
    while(true) {
    	cin >> N >> M;
    	if(N == 0 && M == 0.00) {
    	    break;
	}
	
        vector<int> c(N);
        vector<int> p(N);
        
        for(int i = 0; i < N; ++i) {
            double tmp;
            cin >> c[i] >> tmp;
            p[i] = tmp * 100 + 0.5;
        }
        
        int DP[(int)(M*100) + 1];
        for(int i = 0; i <= (int)(M*100); ++i) {
            DP[i] = 0;
        }
        
        for(int k = 0; k < N; ++k) {
            for(int w = p[k]; w <= (int)(M*100); ++w) {
                DP[w] = max(DP[w], DP[w-p[k]] + c[k]);
            }
        }
        
        cout << DP[(int)(M*100)] << endl;
    }
    
    return 0;
}
