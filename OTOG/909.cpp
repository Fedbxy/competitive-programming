#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int md = 1e9 + 7;
int ans = 0;
vector<int> parent;
vector<vector<int>> child;

ll factorial(ll n) {
    return n == 0 ? 1 : n * factorial(n-1) % md;
}

ll recur(int u) {
    int n = child[u].size();
    if(n == 0) return 1;

    ll sum = 1;
    for(auto e:child[u]) sum = sum * recur(e) % md;
    return factorial(n) * sum % md;
}

int main() {
    int n; cin >> n;
    parent.resize(n+1);
    child.resize(n+1);
    int prev, s;
    for(int i=0;i<2*n-1;i++) {
        int u; cin >> u;
        if(i == 0) {
            s = u;
            prev = u;
            parent[u] = u;
            continue;
        }
        if(!parent[u]) parent[u] = prev;
        prev = u;
    }

    for(int i=1;i<=n;i++) {
        if(parent[i] == i) continue;
        child[parent[i]].push_back(i);
    }

    // for(int i=1;i<=n;i++) {
    //     cout << i << ": ";
    //     for(auto e:child[i]) cout << e << ' ';
    //     cout << '\n';
    // }

    cout << recur(s) % md << '\n';
}