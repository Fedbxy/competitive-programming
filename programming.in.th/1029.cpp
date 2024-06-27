#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m, q; cin >> n >> m >> q;
    set<int> s;
    for(int i=0;i<m;++i) {
        int a, b; cin >> a >> b;
        if(s.find(a) == s.end()) s.insert(a);
        else s.erase(a);
        if(s.find(a + b) == s.end()) s.insert(a + b);
        else s.erase(a + b);
    }
    s.insert(1);
    s.insert(n+1);

    while(q--) {
        int x; cin >> x;
        auto itr = s.upper_bound(x);
        cout << *itr -  *(--itr) << '\n';
    }
    return 0;
}