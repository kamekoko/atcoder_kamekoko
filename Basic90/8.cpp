// https://twitter.com/e869120/status/1379565222541680644/photo/2

// まず単純に再帰呼び出しで全探索 (searchNextChar())　O(S!) くらい?
// 多分動的計画でいける

#include<bits/stdc++.h>
using namespace std;

string s;
long mod = 1000000007;
string ansStr = "atcoder";

long long ansNum;

int searchNextChar(int sPos, int ansStrPos) {
  if (s.size() - sPos < ansStr.size() - ansStrPos) return 0;
  if (ansStrPos == ansStr.size()) {
    ansNum++;
    return 0;
  }
  if (sPos >= s.size()) return 0;

  for (int i = sPos; i < s.size(); i++) {
    if (s[i] == ansStr[ansStrPos]) searchNextChar(i + 1, ansStrPos + 1);
  }
  return 0;
}

int main() {
  cin >> s;

  searchNextChar(0, 0);

  cout << ansNum << '\n';
}
