#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    // freopen("i.txt", "r", stdin);
    char c;
    stack<uint8_t> s;
    while(cin >> c) {
        if(c == 'T') {
            int v; cin >> v;
            s.push(uint8_t(v));
        } else if(c == 'P') s.pop();
        else if(c == 'A') {
            int a = s.top(); s.pop();
            int b = s.top(); s.pop();
            s.push(a + b);
        } else if(c == 'S') {
            int a = s.top(); s.pop();
            int b = s.top(); s.pop();
            s.push(a - b);
        } else if(c == 'M') {
            int a = s.top(); s.pop();
            int b = s.top(); s.pop();
            s.push(a * b);
        } else {
            cout << int(s.top()) << '\n';
        }
    }
    return 0;
}