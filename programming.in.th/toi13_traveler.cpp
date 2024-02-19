#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int,int>;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n,m;cin>>n>>m;
    int s,t,budget;cin>>s>>t>>budget;

    vector<pii> adj[n];
    vector<bool> flag1(n), flag2(n);
    vector<int> dist1(n, INT_MAX), dist2(n, INT_MAX);
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    for(int i=0;i<m;i++) {
        int u,v,w;cin>>u>>v>>w;
        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));
    }

    dist1[s] = 0;
    pq.push(make_pair(dist1[s], s));
    while(!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if(flag1[u]) continue;
        flag1[u] = true;

        for(auto vw:adj[u]) {
            int v = vw.first, w = vw.second;
            if(flag1[v]) continue;
            if(dist1[v] > dist1[u] + w) {
                dist1[v] = dist1[u] + w;
                pq.push(make_pair(dist1[v], v));
            }
        }
    }

    dist2[t] = 0;
    pq.push(make_pair(dist2[t], t));
    while(!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if(flag2[u]) continue;
        flag2[u] = true;

        for(auto vw:adj[u]) {
            int v = vw.first, w = vw.second;
            if(flag2[v]) continue;
            if(dist2[v] > dist2[u] + w) {
                dist2[v] = dist2[u] + w;
                pq.push(make_pair(dist2[v], v));
            }
        }
    }

    int mn = INT_MAX, ans;
    for(int i=0;i<n;i++) {
        if(dist1[i] <= budget and dist2[i] < mn) {
            mn = dist2[i];
            ans = i;
        }
    }
    cout<<ans<<' '<<dist1[ans]<<' '<<dist2[ans]<<'\n';
    return 0;
}