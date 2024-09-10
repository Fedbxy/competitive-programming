#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    string a, b; cin >> a >> b;
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    if (a.size() < b.size()) swap(a, b);

    string ans;
    int sum = 0;
    for (int i=0;i<a.size();++i) {
        sum += i >= b.size() ? a[i] - '0' : a[i] - '0' + b[i] - '0';
        if (sum >= 10) ans.push_back(sum % 10 + '0'), sum /= 10;
        else ans.push_back(sum + '0'), sum = 0;
    }
    if (sum) ans.push_back(sum + '0');

    reverse(ans.begin(), ans.end());
    cout << ans << '\n';
    return 0;
}