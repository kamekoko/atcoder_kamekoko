// Problem 1
// https://twitter.com/e869120/status/1376665578513989633/photo/1

// これは「最小値の最大化」形式の問題
// 今回は二部探索で解ける
// 「答えはM以上か」 -> 「K + 1個以上の「長さM以上のピース」に分割可能か」 -> 貪欲法
// 貪欲法：左から順に調べ、ピースの長さがM以上で初めて切る
// これにすると O(N logL)
// 賢いわ

#include<bits/stdc++.h>
using namespace std;

int ell, n, k;
vector<int> a;
int score;

bool isAvailable(int num) {
    int totalCutNum = 0;
    int preCutPos = 0;
    for (int i = 0; i < n; i++) {
        if (totalCutNum == k) break;
        else {
            if (a[i] - preCutPos >= num) {
                preCutPos = a[i];
                totalCutNum++;
            }
        }
    }
    return (totalCutNum == k) && (ell - preCutPos >= num);
}

int binarySearch(int lower, int upper) {
    if (lower == upper) {
        score = lower;
        return 0;
    }
    int middle = (lower + upper) / 2 + 1;
    if (isAvailable(middle)) binarySearch(middle, upper);
    else binarySearch(lower, middle - 1);
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
    binarySearch(0, ell);
    cout << score << '\n';
}