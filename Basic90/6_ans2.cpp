// https://twitter.com/e869120/status/1379202843622576130/photo/1

// step 2 前処理を追加
// c[i][j] を作成
// c[i][j] = i文字目の右にある文字jの中で最も左にあるもののインデックス
// これは後ろから累積計算すると　O(|S| * 26) = O(|S|) ってのがみそ

#include<bits/stdc++.h>
using namespace std;

string s;
int k;

int c[100009][26];

int main() {
    cin >> s;
    cin >> k;

    // 前処理
    for (int i = 0; i < 26; i++) c[s.size()][i] = s.size();
    for (int i = s.size() - 1; i >= 0; i--) {
        for (int j = 0; j < 26; j++) {
            if ((int)(s[i] - 'a') == j) c[i][j] = i;
            else c[i][j] = c[i + 1][j];
        }
    }

    // 貪欲法
    string ans = "";
    int currentIndex = 0;
    for (int i = 1; i <= k; i++) {
        for (int j = 0; j < 26; j++) {
            int nextIndex = c[currentIndex][j];
            if ((int)(s.size() - 1 - nextIndex) + i >= k) {
                ans += (char)(j + 'a');
                currentIndex = nextIndex + 1;
                break;
            }
        }
    }

    cout << ans << '\n';
    return 0;
}