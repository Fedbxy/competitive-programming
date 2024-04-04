#include <bits/stdc++.h>

using namespace std;

bool ans;

bool ok(vector<int> &a, int p, int x) {
    int sum = 0;
    for(auto e:a) sum += e / x;
    if(sum == p) ans = true;
    return sum >= p;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, p; cin >> n >> p;
    vector<int> a(n); for(int i=0;i<n;i++) cin >> a[i];

    int l = 0, r = *max_element(a.begin(), a.end());
    while(l < r) {
        int mid = l + (r - l) / 2;
        if(ok(a, p, mid)) l = mid + 1;
        else r = mid;
    }
    cout << (ans ? "YES\n" : "NO\n");
    cout << l - 1 << '\n';
    return 0;
}