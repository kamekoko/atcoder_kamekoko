// https://twitter.com/e869120/status/1377027868518064129/photo/2

// 長さ N (1 <= N <= 20) の正しい括弧列を辞書式で全て列挙

// 辞書式の時点で深さ優先探索？
// 再帰呼び出しで
// 正しいかの条件は探索状態として「(」の数を数えておけばよさそう


#include<bits/stdc++.h>
using namespace std;

int n;
vector<string> ans;

int dfs(int bracketNum, string str) {
    if (n == str.size()) {
        if (bracketNum == 0) ans.push_back(str);
        return 0;
    }

    // add (
    bracketNum++;
    if (n - (str.size() + 1) >= bracketNum) dfs(bracketNum, str + "(");
    bracketNum--;

    // add )
    bracketNum--;
    if (bracketNum >= 0) dfs(bracketNum, str + ")");

    return 0;
}

int main() {
    cin >> n;

    dfs(0, "");

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << '\n';
    }
}