#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    string s; cin >> s;
    cout << s;
    reverse(s.begin(), s.end());
    cout << s << '\n';
    return 0;
}