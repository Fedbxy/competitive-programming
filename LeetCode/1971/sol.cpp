class Solution {
private:
    int findSet(vector<int> &parent, int u) {
        if(parent[u] == u) return u;
        return parent[u] = findSet(parent, parent[u]);
    }
    void unionSet(vector<int> &parent, vector<int> &sz, int u, int v) {
        int U = findSet(parent, u), V = findSet(parent, v);
        if(U == V) return;
        if(sz[U] >= sz[V]) {
            parent[V] = U;
            sz[U] += sz[V];
            sz[V] = 0;
        } else {
            parent[U] = V;
            sz[V] += sz[U];
            sz[U] = 0;
        }
    }

public:
    bool validPath(int n, vector<vector<int>>& edges, int s, int t) {
        vector<int> parent(n), sz(n, 1);
        for(int i=0;i<n;++i) parent[i] = i;
        for(auto e: edges) unionSet(parent, sz, e[0], e[1]);
        return findSet(parent, s) == findSet(parent, t);
    }
};