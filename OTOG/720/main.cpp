#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pli = pair<ll,int>;

const int N = 5e4;
int n,m;
string a,b;
ll g, ans1, ans2;
unordered_map<int,ll> star;
unordered_map<string,int> idx;
vector<pli> adj[N];

bool ok(ll x) {
    vector<ll> dist(n, LLONG_MAX);
    vector<bool> flag(n);
    priority_queue<pli, vector<pli>, greater<pli>> pq;

    dist[idx[a]] = 0;
    pq.push({dist[idx[a]], idx[a]});
    while(!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if(flag[u]) continue;
        flag[u] = true;

        for(auto wv:adj[u]) {
            ll w = wv.first; int v = wv.second;
            if(flag[v] or star[v] > x) continue;
            if(dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    if(dist[idx[b]] <= g) ans2 = dist[idx[b]];
    return dist[idx[b]] <= g;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin>>n>>m;
    cin>>a>>b>>g;
    vector<ll> time(n);

    for(int i=0;i<n;i++) {
        string p;ll t;cin>>p>>t;
        idx[p] = i;
        star[i] = t;
        time[i] = t;
    }
    sort(time.begin(), time.end());
    for(int i=0;i<m;i++) {
        string u,v;ll w;cin>>u>>v>>w;
        adj[idx[u]].push_back({w,idx[v]});
        adj[idx[v]].push_back({w,idx[u]});
    }

    int l = 0, r = n - 1;
    while(l<=r) {
        int mid = l + (r - l) / 2;
        if(ok(time[mid])) {
            ans1 = time[mid]; 
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    cout<<ans1<<' '<<ans2<<'\n';
    return 0;
}