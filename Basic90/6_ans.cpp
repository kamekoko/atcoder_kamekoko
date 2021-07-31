// https://twitter.com/e869120/status/1379202843622576130/photo/1

// step 1 最も早い文字を選ぶ。ただしそれより右文字のみで K文字を超えることが条件
// これで O(SK)

#include<bits/stdc++.h>
using namespace std;

string s;
int k;

int searchNextCharIndex(string str, string& ans, int index) {
  int minIndex = str.size();
  int minAscii = 123;
  for (int i = index; i < str.size(); i++) {
    if (ans.size() + (str.size() - i) < k) break;
    if ((int)str[i] < minAscii) {
      minIndex = i;
      minAscii = (int)str[i];
    }
  }

  ans += str[minIndex];
  return minIndex;
}

int main() {
  cin >> s;
  cin >> k;

  string ans = "";
  int index = 0;
  while(ans.size() < k) {
    index = searchNextCharIndex(s, ans, index) + 1;
    cout << ans << endl;
    cout << index << endl;
  }

  cout << ans << endl;
}
