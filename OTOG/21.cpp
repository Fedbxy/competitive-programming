#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    string s; cin >> s;
    int ans = 1, cnt = 1;
    for(auto e:s) if(e == 'i') cnt++; else if(e == ')') ans *= cnt, cnt = 1; ans *= cnt;
    cout << ans << '\n';
    return 0;
}