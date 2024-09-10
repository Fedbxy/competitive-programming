#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    string s;
    vector<string> a;
    while(cin >> s) a.push_back(s);
    
    sort(a.begin(), a.end());
    for(auto e: a) cout << e;
    cout << '\n';

    return 0;
}