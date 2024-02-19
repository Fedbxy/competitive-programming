#include <bits/stdc++.h>
#include "binary_search.h"

using namespace std;
using ll = unsigned long long;

/*
const ll k = 9223372036854775807, N = pow(2, 63);

ll get_n() {
    return N;
}

bool is_equal(ll x) 
{
    cout<<x<<" == "<<k<<'\n';
    return x == k;
}

bool is_less(ll x) {
    return x < k;
}

void answer(ll x) {
    cout<<x<<'\n';
}
*/

int main() {
    ll n = get_n(), ans=-1;
    ll l = 0, r = n;
    int cnt = 0;
    // if(is_equal(n)) {
    //     answer(n);
    //     return 0;
    // }
    while(l<=r) {
        ll mid = l+(r-l)/2;
        if(cnt >= 50) {
            for(ll i=l;i<=r;i++) {
                if(is_equal(i)) ans = i;
            }
            break;
        }
        if(!is_equal(mid)) cnt++;
        if(is_equal(mid)) {
            ans=mid;
            break;
        } else if(is_less(mid)) l = mid;
        else r = mid;
    }
    answer(ans);
    return 0;
}