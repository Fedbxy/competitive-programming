#include <bits/stdc++.h>

using namespace std;

void recur(int k, int w, int l, string ans) {
    if(w >= k or l >= k) {
        for(auto e:ans) cout << e << ' ';
        cout << '\n';
        return;
    }
    if(w + l > 2 * k - 1) {
        return;
    }

    recur(k, w + 1, l, ans + 'W');
    recur(k, w, l + 1, ans + 'L');
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int k, a, b; cin >> k >> a >> b;
    recur(k, a, b, "");
    return 0;
}