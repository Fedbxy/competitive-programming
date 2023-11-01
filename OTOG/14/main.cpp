#include <bits/stdc++.h>

using namespace std;

struct kingdom {
    int worker = 1;
    int soldier = 0;
};

void func(int y, int cnt, kingdom &x) {
    if(cnt == y) return;
    int temp_s = x.soldier, temp_w = x.worker;
    x.worker++;
    x.worker += temp_s;
    x.worker += temp_w;
    x.soldier += temp_w;
    if(temp_w > 0) x.worker-=temp_w;
    if(temp_s > 0) x.soldier-=temp_s;
    func(y, cnt + 1, x);
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int y;
    while(cin>>y) {
        if(y == -1) break;
        kingdom x;
        func(y, 0, x);
        cout<<x.worker<<' '<<x.worker+x.soldier+1<<'\n';
    }
    return 0;
}