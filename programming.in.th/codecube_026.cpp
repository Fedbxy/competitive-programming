#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 10;
int a[N];

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n; cin >> n;
    while(n--) {
        int i, j; cin >> i >> j;
        ++a[i];
        --a[j];    
    }

    for(int i=1;i<N;++i) a[i] += a[i-1];

    cout << *max_element(a, a+N) << '\n';

    return 0;
}