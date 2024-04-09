#include <bits/stdc++.h>

using namespace std;

int n, c, d, a;
int arr[505][505];

void solve() {
    map<int, int> m;
    int mn = INT_MAX;
    cin >> n >> c >> d;
    for(int i = 0; i < n * n; ++i) {
        cin >> a;
        mn = min(mn, a);
        m[a]++;
    }

    bool ans = true;
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j) {
            if(i == 1 and j == 1) arr[i][j] = mn;
            else if(j == 1) arr[i][j] = arr[i-1][j] + c;
            else if(i == 1) arr[i][j] = arr[i][j-1] + d;
            else {
                int res1 = arr[i-1][j] + c;
                int res2 = arr[i][j-1] + d;
                if(res1 != res2) {
                    ans = false;
                    goto done;
                }
                arr[i][j] = res1;
            }
            if(m.find(arr[i][j]) == m.end() or --m[arr[i][j]] == -1) {
                ans = false;
                goto done;
            }
        }
    }

    // for(int i = 1; i <= n; ++i) {
    //     for(int j = 1; j <= n; ++j) {
    //         cout << arr[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }

    done: cout << (ans ? "YES" : "NO") << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}