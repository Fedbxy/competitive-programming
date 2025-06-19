#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    string s; cin >> s;
    string ans;
    for (auto &e: s) if (e >= 'A' and e <= 'z') ans.push_back(e);
    cout << ans << '\n';
    return 0;
}