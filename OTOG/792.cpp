#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;

const unordered_map<char, pii> d = {
    {'L', {0, -1}},
    {'R', {0, 1}},
    {'U', {-1, 0}},
    {'D', {1, 0}}
};

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m, s; cin >> n >> m >> s;
    vector<vector<char>> a(n, vector<char> (m));
    for (auto& i: a) for (auto& j: i) cin >> j;
    
    int i = 0, j = 0;
    while (s--) {
        char c; cin >> c;
        i += (*d.find(c)).second.first;
        j += (*d.find(c)).second.second;
    }

    cout << a[i][j] << '\n';
    return 0;
}

// #include <bits/stdc++.h>

// using namespace std;
// using pii = pair<int, int>;

// int main() {
//     cin.tie(nullptr)->sync_with_stdio(false);
//     int n, m, s; cin >> n >> m >> s;
//     vector<vector<char>> a(n, vector<char> (m));
//     for (auto& i: a) for (auto& j: i) cin >> j;
    
//     int i = 0, j = 0;
//     while (s--) {
//         char c; cin >> c;
//         if (c == 'L') j += -1;
//         else if (c == 'R') j += 1;
//         else if (c == 'U') i += -1;
//         else i += 1;
//     }

//     cout << a[i][j] << '\n';
//     return 0;
// }