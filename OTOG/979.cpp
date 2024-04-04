#include <bits/stdc++.h>

using namespace std;

const double EPS = 1e-7;

struct Part {
    int a, b, c;
};

bool ok(vector<Part> &part, int k, double x) {
    double power = 0;
    for(auto [a, b, c]: part) power += a * x + pow(x, b) + pow(x, c);
    // cout << "#" << power << " >= " << k << '\n';
    // return power >= k;
    return power - k >= EPS;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, k; cin >> n >> k;
    vector<Part> part;
    for(int i=0;i<n;i++) {
        int a, b, c; cin >> a >> b >> c;
        part.push_back({a, b, c});
    }

    double l = 0, r = 1;
    while(abs(r - l) > EPS) {
        double mid = (l + r) / 2;
        // cout << mid << '\n';
        if(ok(part, k, mid)) r = mid;
        else l = mid + EPS;
    }
    cout << fixed << setprecision(2);
    cout << ceil(r * 10000) / 100 << '\n';
    return 0;
}