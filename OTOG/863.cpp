#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n; cin >> n;
    vector<string> a(n);
    for(int i=0;i<n;i++) cin >> a[i];
    int q = 2 * n - 1, idx = -1;
    stack<string> s;
    while(q--) {
        string cmd; cin >> cmd;
        if(cmd == "SHIFT") {
            s.push(a[++idx]);
        } else if(cmd == "RIGHT") {
            string temp = s.top();
            s.pop(); s.pop();
            s.push(temp);
        } else {
            s.pop();
        }
    }
    cout << s.top() << '\n';
    return 0;
}