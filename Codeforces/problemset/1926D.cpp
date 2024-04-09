#include <bits/stdc++.h>

using namespace std;

string func(int n) {
    string s(31, '0');
    for(int i=30;i>=0;i--) {
        if(n >= pow(2, i)) {
            n -= pow(2, i);
            s[i] = '1';
        }
    }
    return s;
}

string swapp(string s) {
    for(auto &e:s) {
        if(e == '1') e = '0';
        else e = '1';
    }
    return s;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        int a[n];
        map<string, int> m;
        for(int i=0;i<n;i++) cin >> a[i];
        for(int i=0;i<n;i++) m[func(a[i])]++;

        int ans = 0;
        for(auto e:m) {
            // cout<<e.first<<' '<<e.second<<'\n';
            ans += e.second;
            if(m.find(swapp(e.first)) != m.end() and m[swapp(e.first)]) m[swapp(e.first)] = max(0, m[swapp(e.first)] - e.second);
            m[e.first] = 0;
        }
        cout << ans << '\n';
    }
    return 0;
}