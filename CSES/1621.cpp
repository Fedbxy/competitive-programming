/*

old submission

#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int n;cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    set<int> s;
    for(int e:a) s.insert(e);
    cout<<s.size()<<'\n';
    return 0;
}
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a.begin(), a.end());
    int prev = a[0], ans = 1;
    for(int i=1;i<n;i++) if(a[i]!=prev) {ans++;prev=a[i];}
    cout<<ans<<'\n';
    return 0;
}