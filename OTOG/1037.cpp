#include <bits/stdc++.h>

using namespace std;

bool check(string& s, int i, int j) {
    if (i >= j) return true;
    if (s[i] != s[j]) return false;
    return check(s, i + 1, j - 1);
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    string s; cin >> s;
    cout << (check(s, 0, s.size() - 1) ? "yes" : "no") << '\n';
    return 0;
}