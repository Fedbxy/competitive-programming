// written by poom
// score: 15/15

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

string rever(string k) {
    string res = "";
    int n = k.size();
    for (int i = n - 1; i >= 0; i--) {
        res += k[i];
    }
    return res;
}

string solve(string a, string b) {
    int p = a.size();
    int q = b.size();

    int i = 0, cur = 0;

    a = rever(a);
    b = rever(b);

    string res = "";

    while (i < p && i < q) {
        int total = (a[i] - '0') + (b[i] - '0') + cur;

        if (total > 9) {
            total -= 10;
            cur = 1;
        }
        else {
            cur = 0;
        }

        res += (total + '0');
        i++;
    }

    while (i < p) {
        int total = (a[i] - '0') + cur;

        if (total > 9) {
            total -= 10;
            cur = 1;
        }
        else {
            cur = 0;
        }

        res += (total + '0');
        i++;
    }

    while (i < q) {
        int total = (b[i] - '0') + cur;

        if (total > 9) {
            total -= 10;
            cur = 1;
        }
        else {
            cur = 0;
        }

        res += (total + '0');
        i++;
    }

    if (cur) {
        res += '1';
    }

    return rever(res);
}

int main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(false);

    string a, b;
    cin >> a >> b;
    cout << solve(a, b);
}