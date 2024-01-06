#include <bits/stdc++.h>

using namespace std;

int k;

void func(string s, int cntw, int cntl) {
    if(cntw == k or cntl == k) {
        for(int i=0;i<s.size();i++) cout<<s[i]<<(i==s.size()-1 ? "\n" : " ");
        return;
    }
    if(cntw + 1 <= k) func(s + "W", cntw + 1, cntl);
    if(cntl + 1 <= k) func(s + "L", cntw, cntl + 1);
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int a,b;cin>>k>>a>>b;
    func("", a, b);
    return 0;
}