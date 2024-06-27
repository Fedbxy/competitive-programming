#include <bits/stdc++.h>

using namespace std;

void solve() {
    string s; cin >> s;
    int n = s.size();
    char temp = s[0];
    bool check = true;
    for(int i=1;i<n;++i) if(s[i] != temp) check = false;
    if(check) cout << "NO\n";
    else {
        cout << "YES\n";
        s += s;
        for(int i=1;i<=n;++i) cout << s[i];
        cout << '\n';
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}