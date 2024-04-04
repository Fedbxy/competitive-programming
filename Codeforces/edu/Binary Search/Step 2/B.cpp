#include <bits/stdc++.h>

using namespace std;

bool ok(vector<int> &a, int k, double x) {
    int total = 0;
    for(auto e:a) total += e / x;
    return total >= k;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, k; cin >> n >> k;
    double l = 0, r = INT_MIN;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin >> a[i], r = max(r, double(a[i]));

    while(l < r) {
        double mid = l + (r - l) / 2;
        if(ok(a, k, mid)) l = mid;
        else r = mid - 1e-6;
    }
    cout << fixed << setprecision(6) << l << '\n';
    return 0;
}