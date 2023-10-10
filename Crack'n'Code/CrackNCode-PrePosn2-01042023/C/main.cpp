#include <bits/stdc++.h>

using namespace std;
using pii = pair<int,int>;

const int N=10e9+10;
const int K=31;
vector<pii> a;
vector<int> dp;

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int n,k,c0;cin>>n>>k>>c0;
    a.resize(k);
    dp.resize(k);
    for(int i=0;i<k;i++){
        int p,c;cin>>p>>c;
        a[i].first=p;a[i].second=c;
    }
    return 0;
}