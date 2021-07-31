// https://twitter.com/e869120/status/1377391097836544001/photo/2

// 入力のグラフは必ず木
// 各頂点始点で深さ優先探索して、最も深く行けたものの深さプラス１が答え?
// このやりかたやと O(N * (N + E)) ?

// 素晴らしい誤答
// これだと予測の通り O(N^2) になり TLE らしい

#include<bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> adjacencyList(10000);

int dfs(int u, int depth, vector<bool> seen) {
    int copyDepth = depth;
    for (int v : adjacencyList[u - 1]) {
        if (seen[v - 1]) continue;
        seen[v - 1] = true;
        depth = max(depth, dfs(v, copyDepth + 1, seen));
        seen[v - 1] = false;
    }
    return depth;
}

int main() {
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adjacencyList[u - 1].push_back(v);
        adjacencyList[v - 1].push_back(u);
    }
    
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        vector<bool> seen(n);
        ans = max(ans, dfs(i, 0, seen));
    }
    cout << ans << '\n';
}