#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;
    string s; cin >> s;

    int a = 0, b = 0;
    int sz_a = 0, sz_b = n;
    for(auto e:s) if(e == '1') b++;

    vector<int> ans;
    for(int i=0;i<=n;i++) {
        if(i == 0) {
            if(b >= ceil(1.0 * sz_b / 2)) ans.push_back(i);
            continue;
        }

        sz_a++;
        sz_b--;
        if(s[i-1] == '0') a++;
        else b--;
        // cout << i << " " << a << ":" << sz_a << " " << b << ":" << sz_b <<'\n';

        if(a >= ceil(1.0 * sz_a / 2) and b >= ceil(1.0 * sz_b / 2)) ans.push_back(i);
    }

    double out = INT_MAX;
    int real_ans = 0;
    for(int i=ans.size()-1;i>=0;i--) {
        // cout << "#" << ans[i] << '\n';
        // cout << "cal: " << abs(1.0 * n / 2 - ans[i]) << '\n';
        if(abs(1.0 * n / 2 - ans[i]) <= out) {
            out = abs(1.0 * n / 2 - ans[i]);
            real_ans = ans[i];
        }
    }
    cout << real_ans << "\n";
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    // freopen("i.txt", "r", stdin);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}