#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n; cin >> n;
    string s; cin >> s;

    set<ll, greater<ll> > ans;
    for (int mask = 0; mask < 1 << n; ++mask) {
        string tmp;
        for (int i = 0; i < n; ++i) if (mask & (1 << i)) tmp.push_back(s[i]);
        ans.insert(tmp.empty() ? 0 : stoll(tmp));
    }

    for(auto &e: ans) cout << e << '\n';
    return 0;
}