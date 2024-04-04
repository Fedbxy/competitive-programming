#include <bits/stdc++.h>

using namespace std;

void solve() {
    string s; cin >> s;
    vector<int> a(10);
    for(int i=0;i<4;i++) {
        if(s[i] == 'A') a[i] = 10;
        else if(s[i] >= 'B' and s[i] <= 'K') a[i] = s[i] - 'B' + 12;
        else if(s[i] >= 'L' and s[i] <= 'U') a[i] = s[i] - 'L' + 23;
        else a[i] = s[i] - 'V' + 34;
    }
    for(int i=4;i<10;i++) a[i] = s[i] - '0';
    int sum = 0;
    for(int i=0;i<10;i++) sum += pow(2, i) * a[i];
    int temp = sum / 11;
    // cout << sum  << ' ' << temp << '\n';
    // cout << (temp * 11 - sum) % 10 << " == " << s[10] << '\n';
    if(abs(temp * 11 - sum) == s[10] - '0') cout << s << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}