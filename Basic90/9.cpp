// https://twitter.com/e869120/status/1379927227739987972/photo/2

// 一つ調べるたびに空間を切っていくんやろうけど分からん
// 全探索で O(N C 3) ~= O(N!)?

#include<bits/stdc++.h>
using namespace std;

#define PI 3.141592653589793
int N;
long long X[2001];
long long Y[2001];

long double calcAngle(long long x1, long long y1, long long x2, long long y2, long long x3, long long y3) {
    long long vecAx = x1 - x2;
    long long vecAy = y1 - y2;
    long long vecBx = x3 - x2;
    long long vecBy = y3 - y2;

    long double cos = (vecAx * vecBx + vecAy * vecBy) / (sqrt(vecAx * vecAx + vecAy * vecAy) * sqrt(vecBx * vecBx + vecBy * vecBy));
    long double ans = acos(cos) * 180.0 / PI;

    return ans;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) cin >> X[i] >> Y[i];

    long double maxAngle = 0;
    for (int i = 0; i < N - 2; i++) {
        for (int j = i + 1; j < N - 1; j++) {
            for (int k = j + 1; k < N; k++) {
                long double new1 = calcAngle(X[i], Y[i], X[j], Y[j], X[k], Y[k]);
                maxAngle = max(maxAngle, new1);
                long double new2 = calcAngle(X[j], Y[j], X[k], Y[k], X[i], Y[i]);
                maxAngle = max(maxAngle, new2);
                long double new3 = calcAngle(X[k], Y[k], X[i], Y[i], X[j], Y[j]);
                maxAngle = max(maxAngle, new3);
            }
        }
    }

    cout << maxAngle << '\n';
}