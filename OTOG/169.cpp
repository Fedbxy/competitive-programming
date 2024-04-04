#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n; cin >> n;
    for(int i=1;i<=(n-1)/2;i++) {
        for(int j=1;j<=(n-1)/2-i+1;j++) cout << ' ';
        for(int j=1;j<=2*i-1;j++) cout << (j%2 == 1 ? '*' : '^');
        cout << '\n';
    }
    for(int i=1;i<=n;i++) if(i == (n+1)/2) cout << 'N'; else cout << (i%2 == 1 ? '*' : '^');
    cout << '\n';
    for(int i=(n-1)/2;i>=1;i--) {
        for(int j=1;j<=(n-1)/2-i+1;j++) cout << ' ';
        for(int j=1;j<=2*i-1;j++) cout << (j%2 == 1 ? '*' : '^');
        cout << '\n';
    }
    return 0;
}