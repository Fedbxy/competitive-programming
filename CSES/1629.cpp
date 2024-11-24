#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n; cin >> n;
    vector<pii> a(n);
    for (auto& e: a) cin >> e.second >> e.first;

    sort(a.begin(), a.end());
    int cnt = 0, now = 0;
    for (auto& e: a) if (e.second >= now) now = e.first, ++cnt;
    cout << cnt << '\n';
    return 0;
}