#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n; cin >> n;
    string s; cin >> s;
    s += s;
    
    for(int i=1;i<=n;++i) {
        if(n % i) continue;
        bool check = true;
        for(int j=0;j<n;++j) {
            if(s[j] != s[j+i]) {
                check = false;
                break;
            }
        }
        if(check) {
            cout << i << '\n';
            return 0;
        }
    }
    return 0;
}