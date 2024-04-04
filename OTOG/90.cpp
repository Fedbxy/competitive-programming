#include <bits/stdc++.h>

using namespace std;

bool ok(vector<int> &a, int b, int x) {
    int cnt = 0;
    for(auto e:a) cnt += ceil(1.0 * e / x);
    return cnt <= b;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, b; cin >> n >> b;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin >> a[i];

    int l = 0, r = 5e6 + 10;
    while(l < r) {
        int mid = l + (r - l) / 2;
        if(ok(a, b, mid)) r = mid;
        else l = mid + 1;
    }
    cout << r << '\n';
    return 0;
}