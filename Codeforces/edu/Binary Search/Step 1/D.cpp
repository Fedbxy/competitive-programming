/* 

NO STL

#include <bits/stdc++.h>

using namespace std;

void func(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int p(vector<int> &a, int start, int end) {
    int pivot = a[end];
    int i = start - 1;
    for(int j=start;j<end;j++) {
        if(a[j]<pivot) {
            i++;
            func(a[i],a[j]);
        }
    }
    i++;
    func(a[i],a[end]);
    return i;
}

void qs(vector<int> &a, int start, int end) {
    if(start>=end) return;
    int pivot = p(a,start,end);
    qs(a, start, pivot - 1);
    qs(a, pivot + 1, end);
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
    qs(a, 0, n-1);
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