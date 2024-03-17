#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int n;
vector<pii> arr;
vector<ll> ans;

void func(int idx, int a, int b) {
    if(idx == n) {
        if(a != 1 or b != 0) ans.push_back(abs(a - b));
        return;
    }
    func(idx + 1, a, b);

    a *= arr[idx].first;
    b += arr[idx].second;
    func(idx + 1, a, b);
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n;
    arr.resize(n);
    for(int i=0;i<n;i++) cin >> arr[i].first >> arr[i].second;

    func(0, 1, 0);

    for(auto &e:ans) {
        ll res = 0;
        for(int i=1;i<=e;i++) res += pow(i, 3);
        for(int i=1;i<=e;i++) res -= pow(i, 2);
        for(int i=1;i<=e;i++) res += i;
        e = res;
    }

    cout << *min_element(ans.begin(), ans.end()) << '\n';
    return 0;
}