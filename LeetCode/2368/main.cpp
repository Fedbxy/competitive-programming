#include <bits/stdc++.h>

using namespace std;

int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
    vector<int> adj[n];
    vector<bool> flag(n);
    unordered_set<int> s(restricted.begin(), restricted.end());
    
    for(auto e:edges) {
        int u = e[0], v = e[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    flag[0] = true;
    queue<int> q;q.push(0);
    while(!q.empty()) {
        int u = q.front();q.pop();
        for(auto v:adj[u]) {
            if(!flag[v] and s.find(v) == s.end()) flag[v] = true, q.push(v);
        }
    }

    int ans = 0;
    for(auto e:flag) if(e) ans++;
    return ans;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n = 7;
    vector<vector<int>> edges = {{0,1},{1,2},{3,1},{4,0},{0,5},{5,6}};
    vector<int> restricted = {4,5};
    cout<<reachableNodes(n, edges,restricted)<<'\n';
    return 0;
}