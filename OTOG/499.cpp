#include <bits/stdc++.h>

using namespace std;

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n; cin >> n;
    vector<int> a;

    int cnt = 0;
    while(true) {
        a.emplace_back(++cnt);
        if(a.size() == n) goto done;

        int temp = a.size() - 1;
        for(int i=0;i<temp;++i) {
            a.emplace_back(a[i]);
            if(a.size() == n) goto done;
        }
    }

    done:
    for(int i=0;i<n;++i) {
        cout << i + 1 << ": ";
        for(int j=0;j<a[i];++j) cout << '*';
        cout << '\n';
    }

    return 0;
}