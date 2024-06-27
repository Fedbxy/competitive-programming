#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;

vector<pii> route(int N, vector<int> W) {
    vector<pii> ans;
    int remaining = W.size();
    int node = N - 1;

    for(int u=1;u<=N;++u) {
        ans.emplace_back(u, u + 1);
        --node;
        if(!--remaining) goto done;
        for(int v=1;v<=u-1;++v) {
            ans.emplace_back(v, u + 1);
            if(!--remaining) goto done;
        }
    }

    done:
    while(node--) {
        for(int i=0;i<W.size();++i) {
            if(ans[W.size() - node - 1 - i].first - ans[W.size() - node - 1 - i].second != -1) {
                ans[W.size() - node - 1 - i] = make_pair(N - node - 1, N - node);
                break;
            }
        }
    }

    return ans;
}

// runner
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, m; cin >> n >> m;
    vector<int> w(m);
    for(int i=0;i<m;++i) cin >> w[i];

    vector<pii> ans = route(n, w);
    for(int i=0;i<ans.size();++i) cout << ans[i].first << ' ' << ans[i].second << ' ' << w[i] << '\n';

    return 0;
}

/*
4 4
10 20 30 40

6 7
10 10 10 10 10 10 10

5 4
10 10 10 10

5 4
10 20 30 40

6 9
1 2 3 4 5 6 7 8 9
*/