#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, k, p; cin >> n >> k >> p;
    vector<int> a(n), b;
    for(auto &e: a) cin >> e;
    
    b = a;
    sort(b.begin(), b.end());

    int l = 0, r = n;
    while(l < r) {
        int mid = l + (r - l) / 2;
        
        int cnt = 0;
        for(int i=0;i<n;++i) {
            if(a[i] > b[mid]) {
                ++cnt;
                i += p - 1;
            }
        }
        
        if(cnt <= k) r = mid;
        else l = mid + 1;
    }
    cout << b[r] << '\n';
    return 0;
}