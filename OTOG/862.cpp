#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    const int N = 1e6 + 10;
    vector<bool> isPrime(N+1, true);
    isPrime[0] = isPrime[1] = false;
    for(int i=2;i*i<=N;i++) for(int j=i*i;j<=N;j+=i) isPrime[j] = false;

    int n, k; cin >> n >> k;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin >> a[i];

    vector<int> idx;
    for(int i=0;i<n;i++) if(isPrime[a[i]]) idx.push_back(i);

    int ans = INT_MAX;
    for(int i=0;i<idx.size()-k+1;i++) ans = min(ans, idx[i+k-1] - idx[i] + 1);
    cout << ans << '\n';
    return 0;
}