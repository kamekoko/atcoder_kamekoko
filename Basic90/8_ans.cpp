// https://twitter.com/e869120/status/1379927227739987972/photo/1

// 状態 DP 使うらしい
// dp[s の pos][atcoderの何文字目] = 通り数
// 基本左をコピーで 文字が一致した場合に一文字進む = 一行上一列左の通り数を一列左の通り数に足す

#include<bits/stdc++.h>
using namespace std;

string S;
string ansStr = "atcoder";
int dp[100009][8];
int mod = 1000000007;

int main() {
  cin >> S;

  dp[0][0] = 1;
  for (int i = 0; i < S.size(); i++) {
    for (int j = 0; j < 8; j++) {
      dp[i + 1][j] += dp[i][j];
      if (S[i] == ansStr[j]) dp[i + 1][j + 1] = dp[i][j];
    }
    for(int j = 0; j < 8; j++) dp[i + 1][j] %= mod;
  }

  cout << dp[S.size()][7] << '\n';
}
