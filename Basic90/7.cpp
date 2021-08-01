// https://twitter.com/e869120/status/1379202843622576130/photo/2

// 全探索で O(NQ)
// sort (O(NlogN)) して 二部探索 (QlogN) で多分 O((N + Q)logN) か

#include<bits/stdc++.h>
using namespace std;

int n, q;
long A[100009];
long B[100009];

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) cin >> A[i];
  cin >> q;
  for (int i = 0; i < q; i++) cin >> B[i];

  long ans = 100009;

  // all search
  // for (int i = 0; i < q; i++) {
  //   for (int j = 0; j < n; j++) {
  //     if (ans > abs(A[j] - B[i])) ans = abs(A[j] - B[i]);
  //   }
  // }

  // sort & binarysearch
  sort(A, A + n);

  

  cout << A[0] << '\n';

  cout << ans << '\n';
  return 0;
}
