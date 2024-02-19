#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;cin>>t;
    while(t--) {
        string s;cin>>s;
        int a = 0, b = 0;
        for(auto e:s) {
            if(e == 'A') a++;
            else b++;
        }
        cout<<(a > b ? "A\n" : "B\n");
    }
    return 0;
}