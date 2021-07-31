// https://twitter.com/e869120/status/1378840212449595393/photo/1

// できない

#include<bits/stdc++.h>
using namespace std;

string S;
int k;

// string getFastestChar(string str, string ans) {
//     int minCode = 123;
//     char minChar = '{';
//     int minPos = str.size();
//     for (int i = 0; i < str.size(); i++) {
//         int code = (int)str[i];
//         if (minCode > code) {
//             minCode = code;
//             minChar = str[i];
//             minPos = i;
//         }
//     }
//     ans += minChar;
//     return str.substr(minPos + 1);
// }

map<char, int> makeOldStrMap(string str) {
    map<char, int> mp;
    for (int i = 0; i < str.size(); i++) {
        mp[str[i]] = i;
    }
    return mp;
}

map<char, int> makeResidualMap(string str) {
    map<char, int> mp;
    for (int i = 0; i < str.size(); i++) {
        mp[str[i]] = str.size() - 1 - i;
    }
    return mp;
}

string stackToStr(stack<char> st) {
    string copy;
    while(st.size() > 0) {
        copy += st.top();
        st.pop();
    }

    string ans;
    for (int i = copy.size() - 1; i >= 0; i--) {
        ans += copy[i];
    }
    return ans;
}

string sortStr(string str) {
    stack<char> st1;
    stack<char> st2;

    for (int i = 0; i < str.size(); i++) {
        if (i == 0) st1.push(str[i]);
        else {
            char latestChar = st1.top();
            char newChar = str[i];
            if ((int)latestChar > (int)newChar) {
                while ((int)latestChar > (int)newChar && st1.size() > 0) {
                    st2.push(latestChar);
                    st1.pop();
                    latestChar = st1.top();
                }
                st1.push(newChar);
                while(st2.size() > 0) {
                    st1.push(st2.top());
                    st2.pop();
                }
            }
            else st1.push(newChar);
        }
    }

    return stackToStr(st1);
}

// int getNextChar(map<char, int> mp, string str, string ans, int count) {
//     map<char, int> residualMp = makeResidualMap(str);
//     for (int i = 0; i < ss.size(); i++) {
//         if (residualMp[ss[i]] > (k - count)) {
//             getNextChar()
//             break;
//         }
//     }
//     return ans;
// }

string getAns(string str) {
    string ss = sortStr(str);
    map<char, int> mp = makeOldStrMap(str);
    string ans = "";
    getNextChar(mp, ss, ans, 0);
}

int main() {
    cin >> S;
    cin >> k;

    cout << << endl;
}

