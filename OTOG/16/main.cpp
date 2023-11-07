#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;cin>>n;
    vector<int> a(n),ans,temp;
    for(int i=0;i<n;i++) cin>>a[i];
    int mx = INT_MIN, sum = 0;
    for(int i=0;i<n;i++) {
        if(sum + a[i] >= a[i]) {
            sum += a[i];
            temp.push_back(a[i]);
        } else {
            sum = a[i];
            temp.clear();
            temp.push_back(a[i]);
        }
        if(sum>mx) {
            mx = sum;
            ans = temp;
        }
    }
    if(mx<=0) {
        cout<<"Empty sequence\n";
        return 0;
    }
    for(int i=0;i<ans.size();i++) cout<<ans[i]<<(i==ans.size()-1 ? '\n' : ' ');
    cout<<mx<<'\n';
    return 0;
}