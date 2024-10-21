#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    vector<int> a;
    int x;
    while (cin >> x) a.emplace_back(x);
    reverse(a.begin(), a.end());

    int tmp = -1, ans = 0;
    for(auto e: a) if (e > tmp) ++ans, tmp = e;
    cout << ans;
    return 0;
}