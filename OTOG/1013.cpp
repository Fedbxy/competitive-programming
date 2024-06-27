#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

template<typename T>
    using oset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, l; cin >> n >> l;
    int a, b; cin >> a >> b;
    --a;
    --b;

    oset<int> s;
    for(int i=0;i<n;++i) {
        int w; cin >> w;
        s.insert(w);
    }

    while(l--) {
        auto itra = s.find_by_order(a);
        auto itrb = s.find_by_order(b);

        int x = *itra, y = *itrb;
        s.erase(itra);
        s.erase(itrb);
        s.insert(y - x);
        s.insert((x + y) / 2);
    }

    for(auto e: s) cout << e << ' ';
    cout << '\n';
    return 0;
}