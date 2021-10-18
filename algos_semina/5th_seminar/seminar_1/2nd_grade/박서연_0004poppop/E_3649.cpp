// 3649 (골드4) 로봇 프로젝트

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);
    
    vector<int> v;
    int hole;    // 구멍의 너비
    
    while (true){
        // 테스트 케이스가 여러 개라는 조건이 있음
        // 몇 개인지 모르기 때문에 값 입력받는다면 반복 실행
        if(cin>>hole){   
            hole*=10000000;    // 단위 통일
            int num,len;    // 레고 조각의 수, 레고 조각의 길이
            
            cin >> num;
            
            v.clear();    // 반복 실행하기 때문에
            for(int i=0;i<num;i++){
                cin >> len;
                v.push_back(len);   
            }    // 벡터에 레고 조각 길이들 저장
            
            sort(v.begin(),v.end());    // 오름차순 정렬
            int l=0, r=v.size()-1, sum;    // 벡터에 저장된 레고 조각 길이들 탐색하기 위한 변수
            bool finish=false;
            
            while(l<r){
                sum = v[l]+v[r];
                if(sum==hole){    // 길이가 같다면
                    finish = true;    // 구멍 완벽하게 막을 수 있음
                    cout << "yes "<< v[l]<<" "<<v[r]<<'\n';
                    break;
                }
                else if(sum < hole)  
                    l++;    // 조각들 길이 합을 늘림
                else 
                    r--;    // 조각들 길이 합을 줄임
            }
            if(!finish)
                cout << "danger\n";
        }
        else break;
    }
    return 0;
}
