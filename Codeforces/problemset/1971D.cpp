#include <bits/stdc++.h>

using namespace std;

void solve() {
    string s; cin >> s;
    int n = s.size();
    if(n == 1) {
        cout << 1 << '\n';
        return;
    }

    int ans = 1;
    for(int i=1;i<n;++i) if(s[i-1] != s[i]) ++ans;
    for(int i=0;i<n;++i) if(s[i-1] == '0' and s[i] == '1') {
        --ans;
        break;
    }
    cout << ans << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}