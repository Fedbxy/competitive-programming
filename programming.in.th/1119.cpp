#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n; cin >> n;
    vector<pii> a(n);
    vector<int> ps(n);
    for(int i=0;i<n;++i) {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a.begin(), a.end(), greater<pii>());
    ps[0] = a[0].first;
    for(int i=1;i<n;++i) ps[i] = ps[i-1] + a[i].first;
    int sum = ps[ps.size()-1];
    
    vector<int> ans(n);
    for(int i=0;i<n;++i) {
        int idx = upper_bound(ps.begin(), ps.end(), sum / 2 - a[i].first) - ps.begin() + 1;
        if(idx - 1 >= i) idx = upper_bound(ps.begin(), ps.end(), sum / 2) - ps.begin();
        ans[a[i].second] = idx;
    }
    for(auto e:ans) cout << e << '\n';
    return 0;
}