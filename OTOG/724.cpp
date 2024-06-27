#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;

const int N = 1e5 + 10;
vector<int> adj1[N], adj2[N];
int t1[N], t2[N];
bool flag1[N], flag2[N];
bool locked1[N], locked2[N];

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, m, q; cin >> n >> m >> q;
    for(int i=0;i<m;++i) {
        int u, v; cin >> u >> v;
        adj1[u].push_back(v);
        adj2[v].push_back(u);
    }

    vector<pii> ask;
    while(q--) {
        int cmd, x; cin >> cmd >> x;
        ask.push_back({cmd, x});
    }

    for(int i=0;i<ask.size();++i) {
        if(ask[i].first == 1) {
            int x = ask[i].second;
            t1[x] = t2[x] = i + 1;
            locked1[x] = locked2[x] = true;
        }
    }

    priority_queue<pii> pq;
    t1[1] = 0;
    pq.push({t1[1], 1});
    while(!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if(flag1[u]) continue;
        flag1[u] = true;

        for(auto v: adj1[u]) {
            if(flag1[v]) continue;
            if(!locked1[v]) t1[v] = max(t1[v], t1[u]);
            pq.push({t1[v], v});
        }
    }

    t2[n] = 0;
    pq.push({t2[n], n});
    while(!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if(flag2[u]) continue;
        flag2[u] = true;

        for(auto v: adj2[u]) {
            if(flag2[v]) continue;
            if(!locked2[v]) t2[v] = max(t2[v], t2[u]);
            pq.push({t2[v], v});
        }
    }

    for(int i=0;i<ask.size();++i) {
        auto [cmd, x] = ask[i];
        if(cmd == 2) {
            cout << (((i + 1) <= t1[x] or not t1[x]) and (((i + 1) <= t2[x]) or not t2[x])) << '\n';
        }
    }

    return 0;
}

/*
8 9 5
1 2
2 3
3 5
4 5
5 6
2 4
5 8
4 7
7 8

2 8
1 5
2 8
1 7
2 8
*/











/*
#include <bits/stdc++.h>

using namespace std;
int bl[100010];
vector<int> adj[100010],adj2[100010];
vector<array<int,2>> v;
priority_queue<array<int,2>> q;
int t[100010],dis[100010],dis2[100010];

int main()
{
    ios::sync_with_stdio(0),cin.tie(0);
    int n,m,Q,a,b,x,y;
    cin>>n>>m>>Q;
    for(int i=0;i<m;i++){
        cin>>a>>b;
        adj[a].push_back(b);
        adj2[b].push_back(a);
    }
    for(int i=1;i<=n;i++) t[i]=INT_MAX;
    for(int i=1;i<=Q;i++){
        cin>>a>>b;
        if(a==1) t[b]=i;
        else v.push_back({i,b});
    }
    dis[1]=INT_MAX;
    q.push({INT_MAX,1});
    while(!q.empty()){
        int now=q.top()[1];
        int nowt=q.top()[0];
        q.pop();
        if(nowt!=dis[now]) continue;
        for(auto e:adj[now]){
            int nextt=min(nowt,t[e]);
            if(nextt>dis[e]){
                dis[e]=nextt;
                q.push({dis[e],e});
            }
        }
    }
    dis2[n]=INT_MAX;
    q.push({INT_MAX,n});
    while(!q.empty()){
        int now=q.top()[1];
        int nowt=q.top()[0];
        q.pop();
        if(nowt!=dis2[now]) continue;
        for(auto e:adj2[now]){
            int nextt=min(nowt,t[e]);
            if(nextt>dis2[e]){
                dis2[e]=nextt;
                q.push({dis2[e],e});
            }
        }
    }
    //for(int i=1;i<=n;i++ ) cout<<dis2[i]<<'\n';
    for(auto e:v){
        if(dis[e[1]]>=e[0]&&dis2[e[1]]>=e[0]) cout<<"1\n";
        else cout<<"0\n";
    }
    return 0;
}
*/