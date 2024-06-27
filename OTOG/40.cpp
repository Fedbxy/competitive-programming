#include <bits/stdc++.h>

using namespace std;

int n, k, l;
int num = 0;

void combi(int cnt, int prev, vector<int> &sel) {
    if(cnt == k) {
        if(++num != l) return;
        for(auto &e: sel) cout << e << ' ';
        cout << '\n';
        return;
    }

    for(int i=prev+1;i<=n;++i) {
        sel.push_back(i);
        combi(cnt + 1, i, sel);
        sel.pop_back();
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n >> k >> l;
    vector<int> sel;
    combi(0, 0, sel);

    // for(int mask=0;mask<1<<n;++mask) {
    //     if(__builtin_popcount(mask) == k) {
    //         if(++num == l) {
    //             for(int i=0;i<n;++i) if((1 << i) & mask) cout << i + 1 << ' ';
    //             cout << '\n';
    //             return 0;
    //         }
    //     }
    // }
    return 0;
}