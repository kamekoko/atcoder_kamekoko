// https://twitter.com/e869120/status/1377752658149175299/photo/2

// このやり方だと O(HW(H + W))

// ans[i][j] = i行目の合計 + j列目の合計 - matrix[i][j] こうすればこの計算は O(1)
// つまり 行と列の合計を入力時にメモしておけば、O(HW) + O(1) = O(HW) でできて TLE 回避

#include<bits/stdc++.h>
using namespace std;

int h,w;

int main() {
    cin >> h >> w;
    vector<vector<int>> matrix(h, vector<int>(w));
    vector<vector<int>> ans(h, vector<int>(w));
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> matrix[i][j];
            for (int k = 0; k < h; k++) {
                ans[k][j] += matrix[i][j];
            }
            for (int k = 0; k < w; k++) {
                if (k == j) continue;
                ans[i][k] += matrix[i][j];
            }
        }
    }

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cout << ans[i][j] << " ";
        }
        cout << '\n';
    }
}