#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    int t;cin>>t;
    while(t--) {
        vector<int> a(3),b(3);
        for(int i=0;i<3;i++) cin>>a[i];
        for(int i=0;i<3;i++) cin>>b[i];
        sort(a.begin(), a.end(), greater<int>());
        sort(b.begin(), b.end(), greater<int>());
        bool tie = true;
        for(int i=0;i<3;i++) {
            if(a[i] == b[i]) continue;
            if(a[i] > b[i]) {
                cout<<"Alice\n";
                tie = false;
                break;
            } else {
                cout<<"Bob\n";
                tie = false;
                break;
            }
        }
        if(tie) {
            cout<<"Tie\n";
        }
    }
    return 0;
}