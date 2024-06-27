#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m, k; cin >> n >> m >> k;
    vector<int> a(n), b(m);
    for(auto &e: a) cin >> e;
    for(auto &e: b) cin >> e;
    
    map<int, int> cnt;
    for(int i=0;i<m;++i) ++cnt[b[i]];

    int ans = 0, sum = 0;
    for(int i=0;i<m;++i) if(cnt.find(a[i]) != cnt.end() and --cnt[a[i]] >= 0) ++sum;
    if(sum >= k) ++ans;

    for(int i=1;i<n-m+1;++i) {
        int j = i + m - 1;
        if(cnt.find(a[j]) != cnt.end() and --cnt[a[j]] >= 0) ++sum;
        if(cnt.find(a[i-1]) != cnt.end() and ++cnt[a[i-1]] > 0) --sum;
        if(sum >= k) ++ans;
    }
    cout << ans << '\n';
    return 0;
}