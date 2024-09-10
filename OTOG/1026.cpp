#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n; cin >> n;
    unordered_set<string> st;
    for (int i=0;i<n;++i) {
        string s; cin >> s;
        int found = s.find("_But_");
        if (found != string::npos) {
            st.emplace(s.substr(0, found));
        } else {
            st.emplace(s);
        }
    }

    cout << st.size() << '\n';
    return 0;
}