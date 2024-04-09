#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    freopen("mixmilk.in", "r", stdin);
    freopen("mixmilk.out", "w", stdout);
    vector<int> cap(3), a(3);
    for(int i = 0; i < 3; i++) cin >> cap[i] >> a[i];

    vector<int> next = {1, 2, 0};
    int t = 0;
    for(int i = 0; i < 100; i++) {
        int next_t = next[t];
        if(a[t] + a[next_t] > cap[next_t]) {
            a[t] = a[t] + a[next_t] - cap[next_t];
            a[next_t] = cap[next_t];
        } else {
            a[next_t] += a[t];
            a[t] = 0;
        }
        t = next_t;

        // for(auto e: a) cout << e << ' ';
        // cout << '\n';
    }
    for(auto e: a) cout << e << '\n';
    return 0;
}