#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> a(6);
vector<int> arr;
vector<vector<int>> ans;

void recur(int r, int cnt) {
    if(cnt <= m and r == 0) {
        ans.push_back(arr);
        return;
    }
    if(r < 0 or cnt > m) return;

    for(auto e:a) {
        arr.push_back(e);
        recur(r - e, cnt + 1);
        arr.pop_back();
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n >> m;
    for(int i=1;i<=6;i++) cin >> a[i-1];

    recur(n, 0);
    
    cout << ans.size() << "\nE\n";
    for(auto e:ans) {
        cout << e.size() << ' ';
        for(auto b:e) cout << b << ' ';
        cout << "\nE\n";
    }
    return 0;
}