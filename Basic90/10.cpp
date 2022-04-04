// https://twitter.com/e869120/status/1380290146340245505/photo/2

#include<bits/stdc++.h>
using namespace std;

int n, q;

int main() {

  cin >> n >> q;
  int c[n], p[n];
  for (int i = 0; i < n; i++) cin >> c[i];
  for (int i = 0; i < n; i++) cin >> p[i];

  for (int k = 0; k < q; k++) {
    int L, R;
    cin >> L >> R;

    int sum1 = 0;
    int sum2 = 0;
    for (int i = L - 1; i < R; i++) {
      if (c[i] == 1) sum1 += p[i];
      else sum2 += p[i];
    }

    cout << sum1 << endl;
    cout << sum2 << endl;
  }
}
