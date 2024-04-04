#include <bits/stdc++.h>

using namespace std;

bool ok(vector<int> &a, int k, int x) {
    int cnt = 1, sum = 0;
    for(auto e:a) {
        sum += e;
        if(sum > x) cnt++, sum = e;
    }
    return cnt <= k;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin >> a[i];

    int l = *max_element(a.begin(), a.end()), r = accumulate(a.begin(), a.end(), 0);
    while(l < r) {
        int mid = l + (r - l) / 2;
        if(ok(a, k, mid)) r = mid;
        else l = mid + 1;
    }
    cout << r << '\n';
    return 0;
}