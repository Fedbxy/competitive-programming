#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; scanf("%d", &n);
    vector<int> a(n), b(n);
    for (auto &e: a) scanf("%d", &e);
    for (auto &e: b) scanf("%d", &e);

    vector<int> ans(n);
    vector<bool> used(n);
    int i = 0, x = 0, y = n - 1;
    while (i < n) {
        if (!used[a[i]]) ans[x++] = a[i], used[a[i]] = true;
        if (!used[b[i]]) ans[y--] = b[i], used[b[i]] = true;
        ++i;
    }

    for (auto &e: ans) printf("%d\n", e);
    return 0;
}