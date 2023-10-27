/*

// NO STL

#include <bits/stdc++.h>

using namespace std;

void merge(vector<int> &l, vector<int> &r, vector<int> &a) {
    int ln = a.size()/2;
    int rn = a.size()-ln;
    int li=0,ri=0,i=0;
    while(li<ln and ri<rn) {
        if(l[li]<r[ri]) {
            a[i]=l[li];
            li++;
        } else {
            a[i]=r[ri];
            ri++;
        }
        i++;
    }
    while(li<ln) {
        a[i]=l[li];
        li++;
        i++;
    }
    while(ri<rn) {
        a[i]=r[ri];
        ri++;
        i++;
    }
}

void ms(vector<int> &a) {
    int n = a.size();
    if(n<=1) return;
    int mid = n/2;
    vector<int> l(mid),r(n-mid);
    for(int i=0;i<mid;i++) l[i]=a[i];
    for(int i=mid;i<n;i++) r[i-mid]=a[i];
    ms(l);
    ms(r);
    merge(l,r,a);
}

int lpos(vector<int> &a, int x) {
    int l=0,r=a.size()-1,ans=-1;
    while(l<=r) {
        int mid = (l+r)/2;
        if(a[mid]>=x) {
            ans = mid;
            r = mid - 1;
        } else l = mid + 1;
    }
    return ans;
}

int rpos(vector<int> &a, int x) {
    int l=0,r=a.size()-1,ans=-1;
    while(l<=r) {
        int mid = (l+r)/2;
        if(a[mid]<=x) {
            ans = mid;
            l = mid + 1;
        } else r = mid - 1;
    }
    return ans;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    ms(a);
    int k;cin>>k;
    while(k--) {
        int x,y;cin>>x>>y;
        int l=lpos(a,x),r=rpos(a,y);
        cout<<(l==-1 or r==-1 ? 0 : r-l+1)<<(k==0 ? '\n' : ' ');
    }
    return 0;
}

*/

// STL

#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a.begin(), a.end());
    int k;cin>>k;
    while(k--) {
        int x,y;cin>>x>>y;
        int l = lower_bound(a.begin(), a.end(), x) - a.begin(), r = upper_bound(a.begin(), a.end(), y) - a.begin() - 1;
        cout<<r-l+1<<(k==0 ? '\n' : ' ');
    }
    return 0;
}