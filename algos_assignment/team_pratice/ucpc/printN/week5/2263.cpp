#include <iostream>

using namespace std;

int n;
int po[100050];
int in[100050];
int inorder_idx[100050];

void ans(int p_point, int i_point, int len) {
   if (len == 0) return;
   int root = po[p_point + len - 1]; //후위순회의 끝값이 시작점
   cout << root << " ";
   int  d_point = inorder_idx[root]; //루트값이 있는 인덱스를 기점으로
   ans(p_point, i_point, d_point - i_point); //좌
   ans(p_point + d_point - i_point, d_point + 1, len - 1 - (d_point - i_point)); //우
}

int main() {
   ios_base::sync_with_stdio(0);
   cin.tie(0), cout.tie(0);
   cin >> n;
   for (int i = 0; i < n; i++) {
      cin >> in[i];
   }
   for (int i = 0; i < n; i++) {
      cin >> po[i];
   }
   for (int i = 0; i < n; i++) {
      inorder_idx[in[i]] = i;
   }
   ans(0, 0, n);
}
