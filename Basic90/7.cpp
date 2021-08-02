// https://twitter.com/e869120/status/1379202843622576130/photo/2

// 全探索で O(NQ)
// sort (O(NlogN)) して 二部探索 (QlogN) で多分 O((N + Q)logN) か
// 二部探索は以下の標準ライブラリが有効
// https://pyteyon.hatenablog.com/entry/2019/02/20/194140

#include<bits/stdc++.h>
using namespace std;

const int INF = 2000000000;
int n, q;
long A[100009];
long B[100009];

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) cin >> A[i];
  cin >> q;
  for (int i = 0; i < q; i++) cin >> B[i];

  // all search => O(NQ)
  // for (int i = 0; i < q; i++) {
  //   int ans = INF;
  //   for (int j = 0; j < n; j++) {
  //     if (ans > abs(A[j] - B[i])) ans = abs(A[j] - B[i]);
  //   }
  //   cout << ans << '\n';
  // }

  // sort & binarysearch => O((N+Q)logN)
  sort(A, A + n);
  for (int i = 0; i < q; i++) {
    int pos = lower_bound(A, A + n, B[i]) - A; // - A でイテレータからインデックス取得
    int diff1, diff2 = INF;
    if (pos < n) diff1 = abs(A[pos] - B[i]);
    if (pos > 0) diff2 = abs(A[pos - 1] - B[i]);
    cout << min(diff1, diff2) << '\n';
  }

  return 0;
}
