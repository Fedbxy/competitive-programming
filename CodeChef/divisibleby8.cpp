#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;cin>>n;
    string s,s3d;cin>>s;
    if(n == 1) {
        cout<<8<<'\n';
        return;
    }
    if(n>3) s3d = s.substr(s.size()-3, 3);
    else s3d = s;
    int num = stoi(s3d);
    if(num%8 == 0) {
        cout<<s<<'\n';
        return;
    }

    if(n == 2) {
        string closest;
        int diff=INT_MAX;
        for(int i=16;i<100;i+=8) {
            string si = to_string(i);
            int temp=0;
            for(int j=0;j<2;j++) if(s3d[j]!=si[j]) temp++;
            if(temp<diff) {
                closest = si;
                diff = temp;
            }
            if(diff == 1) break;
        }
        cout<<closest<<'\n';
        return;
    }

    // n ≥ 3
    string closest;
    int diff=INT_MAX;
    for(int i=8;i<1000;i+=8) {
        string si = to_string(i);
        if(si.size()==1) si = "00" + si;
        else if(si.size()==2) si = "0" + si;
        int temp=0;
        for(int j=0;j<3;j++) if(s3d[j]!=si[j]) temp++;
        if(temp<diff) {
            closest = si;
            diff = temp;
        }
        if(diff == 1) break;
    }
    for(int i=0;i<s.size()-3;i++) cout<<s[i];
    cout<<closest<<'\n';
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    // freopen("i.txt","r",stdin);
    int t;cin>>t;
    while(t--) {
        solve();
    }
    return 0;
}