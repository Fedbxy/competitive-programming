#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int a, b; cin >> a >> b;
    string s; cin >> s;

    int sum = 0;
    reverse(s.begin(), s.end());
    for(int i=0;i<s.size();i++) sum += (s[i] - '0') * pow(a, i); 

    string ans;
    while(sum > 0) {
        ans.push_back((sum % b) + '0');
        sum /= b; 
    }

    reverse(ans.begin(), ans.end());
    cout << ans << '\n';
    return 0;
}