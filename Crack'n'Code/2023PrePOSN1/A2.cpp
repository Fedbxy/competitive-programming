#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n,m;cin>>n>>m;
    if(n<1 and m<1) {
        cout<<0<<'\n';
        return 0;
    }
    int sum=0;
    for(int ax=0;ax<=n;ax++) {
        for(int ay=0;ay<=m;ay++) {
            for(int bx=0;bx<=n;bx++) {
                for(int by=0;by<=m;by++) {
                    for(int cx=0;cx<=n;cx++) {
                        for(int cy=0;cy<=m;cy++) {
                            sum+=abs(ax*by+bx*cy+cx*ay-ay*bx-by*cx-cy*ax);
                        }
                    }
                }
            }
        }
    }
    cout<<sum/6<<'\n';
    return 0;
}