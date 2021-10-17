//구멍의 너비 x미터, 구멍에 넣을 두 조각의 길이 합은 구멍의 너비와 정확히 일치해야함
//구멍을 완벽하게 막을 수 있는 두 조각을 구하는 프로그램
//구멍의 너비와 레고 조각의수, 레고 조각의 길이를 입력받음
//구멍을 완벽하게 막을 수 있는 두 조각이 있는지 없는지 여부에 따라 형식에 맞게 출력문을 출력함
//(정답이 여러 개인 경우 두 조각의 차가 가장 큰 경우를 출력해줌)

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
