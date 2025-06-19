#include <bits/stdc++.h>

using namespace std;

const string ans[] = {
    "31",
    "28-29",
    "31",
    "30",
    "31",
    "30",
    "31",
    "31",
    "30",
    "31",
    "30",
    "31"
};

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int x; cin >> x;
    cout << ans[x - 1] << '\n';
    return 0;
}