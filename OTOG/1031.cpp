#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n; cin >> n;
    while (n--) {
        string a, b; cin >> a >> b;
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        cout << (a == b ? "same" : "not same") << '\n';
    }
    return 0;
}