#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    string s; cin >> s;
    getline(cin, s);
    int n = s.size();
    for (int i = n - 1; i >= 0; --i) {
        if (i == n - 1 and s[i] == ' ') {
            --n;
            continue;
        }
        if (s[i] == ' ') {
            cout << n - i - 1 << '\n';
            return 0;
        }
    }
    cout << n << '\n';
    return 0;
}