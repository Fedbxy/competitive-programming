// #include <bits/stdc++.h>

// using namespace std;

// int n;
// vector<int> c(8), a;
// int ans = INT_MIN;

// void recur(int cnt, vector<int> card, int sum) {
//     if(cnt == n) {
//         ans = max(ans, sum);
//         return;
//     }

//     for(int i=0;i<4;i++) {
//         int chose = card[i];
//         // cout << a[cnt] << ' ' << chose << '\n';
//         // vector<int> temp = card;
//         card.erase(card.begin()+i);
//         card.push_back(chose);
//         recur(cnt + 1, card, sum + abs(chose - a[cnt]));
//         card.insert(card.begin()+i, chose);
//         card.pop_back();
//     }
// }

// int main() {
//     cin.tie(nullptr)->sync_with_stdio(false);
//     cin >> n;
//     for(int i=0;i<8;i++) cin >> c[i];
//     a.resize(n);
//     for(int i=0;i<n;i++) cin >> a[i];
//     recur(0, c, 0);
//     cout << ans << '\n';
//     return 0;
// }

// subtask1
#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> c(8), a;
int ans = INT_MIN;

void recur(int cnt, vector<int> card, int sum) {
    if(cnt == n) {
        ans = max(ans, sum);
        return;
    }

    int res = 0, chose;
    for(int i=0;i<4;i++) {
        if(res < abs(card[i] - a[cnt])) {
            res = abs(card[i] - a[cnt]);
            chose = card[i];
        }
    }
    card.erase(find(card.begin(), card.begin()+4, chose));
    card.push_back(chose);
    recur(cnt + 1, card, sum + res);
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n;
    for(int i=0;i<8;i++) cin >> c[i];
    a.resize(n);
    for(int i=0;i<n;i++) cin >> a[i];
    recur(0, c, 0);
    cout << ans << '\n';
    return 0;
}