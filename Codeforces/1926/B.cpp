#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;cin>>t;
    while(t--) {
        int n;cin>>n;
        char a[n][n];
        for(int i=0;i<n;i++) for(int j=0;j<n;j++) cin>>a[i][j];

        int imin = n, imax = 0, jmin = n, jmax = 0;
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                if(a[i][j] == '1') {
                    imin = min(imin, i);
                    imax = max(imax, i);
                    jmin = min(jmin, j);
                    jmax = max(jmax, j);
                }
            }
        }

        cout << (imax - imin == jmax - jmin ? "SQUARE\n" : "TRIANGLE\n");
    }
    return 0;
}