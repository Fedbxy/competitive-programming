#include <bits/stdc++.h>

using namespace std;

int n,t;
const int N = 1e5 + 10;
vector<int> adj[N], income(N);

bool ok(int x) {
    vector<bool> flag(n);
    int cnt = n;
    for(int i=0;i<n;i++) {
        if(income[i] > x) {
            if (!flag[i]) {
                cnt--;
                flag[i] = true;
            }
            for(auto v:adj[i]) {
                if(!flag[v]) {
                    cnt--;
                    flag[v] = true;
                }
            }
        }
    }
    return cnt >= t;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin>>n>>t;
    vector<int> arr(n);
    for(int i=0;i<n;i++) {
        cin>>income[i];
        arr[i] = income[i];
        int ni;cin>>ni;
        for(int j=0;j<ni;j++) {
            int v;cin>>v;
            adj[i].push_back(v);
            adj[v].push_back(i);
        }
    }
    sort(arr.begin(), arr.end());
    int l = 0, r = n - 1;
    while(l<r) {
        int mid = l + (r - l) / 2;
        if(ok(arr[mid])) r = mid;
        else l = mid + 1;
    }
    cout<<arr[r]<<'\n';
    return 0;
}