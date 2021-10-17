#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    vector<int> v;
    int len;
    while (1){
        if(cin>>len){
            len*=10000000;
            int num,val;
            cin>>num;
            v.clear();
            for(int i=0;i<num;i++){
                cin>> val;
                v.push_back(val);   
            }
            sort(v.begin(),v.end());
            int l=0,r=v.size()-1,sum;
            bool finish=false;
            while(l<r){
                sum = v[l]+v[r];
                if(sum==len){
                    finish = true;
                    cout << "yes "<< v[l]<<" "<<v[r]<<'\n';
                    break;
                }
                else if(sum < len)  l++;
                else r--;
            }
            if(!finish)
                cout << "danger\n";
        }
        else break;
    }
    return 0;
}
