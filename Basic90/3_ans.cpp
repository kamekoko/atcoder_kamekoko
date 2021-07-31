// O(N + N) = O(N) で求めるアルゴ
// 任意の点から一番離れている点探す
// その点から一番離れている点までの距離が木の直径
// 直径 + 1 が答え

#include<bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> adjacencyList(10000);

int dfs(int u, int depth, vector<bool> seen) {
    int copyDepth = depth;
    for (int v : adjacencyList[u - 1]) {
        if (seen[v - 1]) continue;
        seen[v - 1] = true;
        int newDepth = dfs(v, copyDepth + 1, seen);
        depth = max(depth, dfs(v, copyDepth + 1, seen));
        seen[v - 1] = false;
    }
    return depth;
}

vector<int> dijkstra(int s) {
    vector<int> len(n);
    vector<int> prev(n);
    for (int i = 0; i < n; i++) {
        if (i == s) len[i] = 0;
        else len[i] = 100000;
        prev[i] = -1;
    } 
    vector<int> queue;
    for (int i = 0; i < n; i++) {
        queue.push_back(i);
    }

    while(queue.size() > 0) {
        int min = 100000;
        int uIndex = -1;
        int u = -1;
        for (int i = 0; i < queue.size(); i++) {
            if (min > len[queue[i]]) {
                min = len[queue[i]];
                uIndex = i;
                u = queue[i];
            }
        }
        queue.erase(queue.begin() + uIndex);
        for (int v : adjacencyList[u]) {
            if (len[v] > len[u] + 1) {
                len[v] = len[u] + 1;
                prev[v] = u;
            }
        }
    }

    vector<int> r(2); // <index, value>
    r[1] = 0;
    for(int i = 0; i < n; i++) {
        if (r[1] < len[i]) {
            r[0] = i;
            r[1] = len[i];
        }
    }
    return r;
}

int main() {
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adjacencyList[u - 1].push_back(v - 1);
        adjacencyList[v - 1].push_back(u - 1);
    }
    
    int farNode = dijkstra(0)[0];
    cout << dijkstra(farNode)[1] + 1 << '\n';
}