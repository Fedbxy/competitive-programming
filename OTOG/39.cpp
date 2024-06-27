#include <bits/stdc++.h>

using namespace std;

int n, k, l;
int num = 0;

void perm(int cnt, int prev, vector<int> &sel) {
    if(cnt == k) {
        if(++num != l) return;
        for(auto &e: sel) cout << e << ' ';
        cout << '\n';
        return;
    }

    for(int i=1;i<=n;++i) {
        if(find(sel.begin(), sel.end(), i) == sel.end()) {
            sel.push_back(i);
            perm(cnt + 1, i, sel);
            sel.pop_back();
        }
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n >> k >> l;
    vector<int> sel;
    perm(0, 0, sel);
    return 0;
}