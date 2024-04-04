#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, k; cin >> n >> k;
    vector<int> a(n); for(int i=0;i<n;i++) cin >> a[i];

    vector<int> valid;
    for(int i=0;i<n;i++) if((i > 0 ? a[i] > a[i-1] : true) and (i < n - 1 ? a[i] > a[i+1] : true)) valid.push_back(a[i]);
    sort(valid.begin(), valid.end());
    valid.resize(unique(valid.begin(), valid.end()) - valid.begin());
    reverse(valid.begin(), valid.end());
    
    if(valid.size()) {
        if(valid.size() >= k) for(int i=0;i<min((int)valid.size(), k);i++) cout << valid[i] << '\n';
        else for(int i=0;i<min((int)valid.size(), k);i++) cout << valid[valid.size()-i-1] << '\n';
    } else cout << -1 << '\n';
    return 0;
}