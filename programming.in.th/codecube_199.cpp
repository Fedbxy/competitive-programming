#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct edge {
    int u,v,w;
    int idx;
    bool flag = false;
};

bool cmp(const edge &l, const edge &r) {
    return l.w > r.w;
}

const int N = 1e5 + 10;
vector<edge> a;
int parent[N], sz[N];

int findSet(int u) {
    if(parent[u] == u) return u;
    return parent[u] = findSet(parent[u]);
}

void unionSet(int u, int v) {
    int U = findSet(u), V = findSet(v);
    if(U == V) return;
    if(sz[U] >= sz[V]) parent[V] = U, sz[U] += sz[V], sz[V] = 0;
    else parent[U] = V, sz[V] += sz[U], sz[U] = 0;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n,m;cin>>n>>m;
    for(int i=0;i<n;i++) parent[i] = i, sz[i] = 1;
    for(int i=1;i<=m;i++) {
        int u,v,w;cin>>u>>v>>w;
        a.push_back({u,v,w,i});
    }
    int t;cin>>t;
    sort(a.begin(), a.end(), cmp);
    int cnt = 0;
    ll ans1 = 0;
    vector<int> ans2;
    for(int i=0;i<m;i++) {
        if(findSet(a[i].u) != findSet(a[i].v)) {
            ans1 += a[i].w;
            ans2.push_back(a[i].idx);
            unionSet(a[i].u, a[i].v);
            a[i].flag = true;
            cnt++;
        }
    }
    for(int i=0;i<m;i++) {
        if(!a[i].flag) {
            ans1 += a[i].w;
            ans2.push_back(a[i].idx);
            unionSet(a[i].u, a[i].v);
            a[i].flag = true;
            cnt++;
            break;
        }
    }
    if(cnt != n) {
        cout<<-1<<'\n';
        return 0;
    }
    sort(ans2.begin(), ans2.end());
    cout<<ans1<<'\n';
    if(t == 2) for(int i=0;i<ans2.size();i++) cout<<ans2[i]<<(i==ans2.size()-1 ? '\n' : ' ');
    return 0;
}