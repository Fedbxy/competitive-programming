#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;

const int N = 2e3 + 10;
int dist[N];

int f(pii a, pii b) {
    return abs(a.first - b.first) + abs(a.second - b.second);
}

int main() {
    for(int i=0;i<N;++i) dist[i] = INT_MAX;

    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    vector<pii> a;
    int s, t;
    for(int i=1;i<=n;++i) {
        char str[m]; scanf("%s", &str);
        for(int j=1;j<=m;++j) {
            char c = str[j-1];
            if(c == 'A') {
                s = a.size();
                a.emplace_back(i, j);
            } else if(c == 'B') {
                t = a.size();
                a.emplace_back(i, j);
            } else if(c == 'X') {
                a.emplace_back(i, j);
            }
        }
    }

    priority_queue<pii, vector<pii>, greater<pii>> pq;
    dist[s] = 0;
    pq.emplace(dist[s], s);
    while(!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        for(int v=0;v<a.size();++v) {
            int w = f(a[u], a[v]);
            if(w > k) continue;
            if(dist[v] > d + w) {
                dist[v] = d + w;
                pq.emplace(dist[v], v);
            }
        }
    }

    printf("%d\n", dist[t] == INT_MAX ? -1 : dist[t]);

    return 0;
}