// https://twitter.com/e869120/status/1378115289649348611/photo/2

// 単純に考えると、倍数一つずつ調べて、一桁ずつ使える数字か調べる感じか
// 計算量で無理

#include<bits/stdc++.h>
using namespace std;

unsigned getDigit(unsigned num) {
    unsigned digit = 0;
    while (num != 0) {
        num /= 10;
        digit++;
    }
    return digit;
}

bool isAvailable(unsigned num, vector<int> availableNums) {
    while (num != 0) {
        int val = num % 10;
        bool flag = false;
        for (int n : availableNums) {
            if (n == val) flag = true;
        }
        if (! flag) return false;
        num /= 10;
    }
    return true;
}

int main() {
    int n, k, b;
    cin >> k >> n >> b;
    
    vector<int> numVec(k);
    for(int i = 0; i < k; i++) {
        cin >> numVec[i];
    }

    unsigned val = 0;
    while (getDigit(val) < n) {
        val += b;
    }

    int ans = 0;
    while (getDigit(val) == n) {
        if (isAvailable(val, numVec)) ans++;
        val += b;
    }

    cout << ans << '\n';
}