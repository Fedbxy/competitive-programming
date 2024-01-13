// written by poom
// score: 24/30
// this is NOT the solution to this problem

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    string s;
    cin >> s;

    int a, b;
    cin >> a >> b;

    if (a < 2 || a > 36 || b < 2 || b > 36) {
        cout << "error";
        return 0;
    }

    bool ok = true;

    for (int i = 0; i < s.size(); i++) {
        if ('0' <= s[i] && s[i] <= '9') {
            if (s[i] - '0' >= a) {
                ok = false;
                break;
            }
        }
        else if ('A' <= s[i] && s[i] <= 'Z') {
            if (s[i] - 'A' + 10 >= a) {
                ok = false;
                break;
            }
        }
        else {
            ok = false;
            break;
        }
    }

    if (!ok) {
        cout << "error";
        return 0;
    }

    ll total = 0;

    for (int i = 0; i < s.size(); i++) {
        if ('0' <= s[i] && s[i] <= '9') {
            total = (total * a) + (s[i] - '0');
        }
        else {
            total = (total * a) + (s[i] - 'A' + 10);
        }
    }

    stack<char> st;

    while(total > 0) {
        int val = total % b;

        if (0 <= val && val <= 9) {
            st.push(val + '0');
        }
        else {
            st.push(val - 10 + 'A');
        }

        total /= b;
    }

    while (!st.empty()) {
        cout << st.top();
        st.pop();
    }
}