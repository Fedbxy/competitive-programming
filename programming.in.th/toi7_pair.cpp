#include <bits/stdc++.h>

#define int long long

using namespace std;
using pii = pair<int, int>;

vector<pii> a, temp;

bool cmp(const pii &l, const pii &r) {
    if(l.second == r.second) return l.first > r.first;
    return l.second < r.second;
}

int merge(int l, int r) {
    int mid = (l + r) / 2;
    int res = 0;
    int i = l, j = mid + 1, k = 0;
    int sum = 0;
    for(int i=l;i<=mid;++i) sum += a[i].first;
    while(i <= mid and j <= r) {
        if(a[i].first > a[j].first) {
            res += sum + a[j].first * (mid - i + 1);
            temp[k++] = a[j++];
        } else {
            sum -= a[i].first;
            temp[k++] = a[i++];
        }
    }
    while(i <= mid) temp[k++] = a[i++];
    while(j <= r) temp[k++] = a[j++];
    for(int i=l;i<=r;++i) a[i] = temp[i-l];
    return res;
}

int ms(int l, int r) {
    if(l == r) return 0;
    int mid = (l + r) / 2;
    int res = 0;
    res += ms(l, mid);
    res += ms(mid + 1, r);
    res += merge(l, r);
    return res;
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n; cin >> n;
    a.resize(n);
    temp.resize(n);
    for(auto &e: a) cin >> e.first >> e.second;
    sort(a.begin(), a.end(), cmp);

    cout << ms(0, n-1) << '\n';
    return 0;
}