// Problem 1
// https://twitter.com/e869120/status/1376665578513989633/photo/1

// 実行可能解の個数は nCk
// 全探索でも行ける？
// 深さ優先で、score以下になった時点で枝刈り
// O(nCk) = O(n!)?


#include<bits/stdc++.h>
using namespace std;

int ell, n, k;
vector<int> a;
int score;

int branchAndBound(int totalCutNum, int pos, int preCutPos, int newScore) {
    if (k - totalCutNum > n - pos) return 0;
    
    if (totalCutNum == k) {
        if (newScore > ell - a[preCutPos]) newScore = ell - a[preCutPos];
        if (score < newScore) score = newScore;
        return 0;
    }

    // branch 1 : no cut
    branchAndBound(totalCutNum, pos + 1, preCutPos, newScore);

    // branch 2 : cut
    if (newScore > a[pos] - a[preCutPos]) branchAndBound(totalCutNum + 1, pos + 1, pos, a[pos] - a[preCutPos]);
    else branchAndBound(totalCutNum + 1, pos + 1, pos, newScore);

    return 0;
}

int main() {
    cin >> ell >> n >> k;
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        a.push_back(val);
    }

    score = 0;

    branchAndBound(0, 0, -1, ell);

    cout << score << '\n';
}