#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, k; cin >> n >> k;
    
    map<int, bool> m;
    while (n--) {
        int x; cin >> x;
        m[x % k] = true;
    }
    
    cout << m.size() << '\n';
    return 0;
}