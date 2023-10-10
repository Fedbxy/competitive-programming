#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int m,n;
    cin>>m>>n;
    int m1[m][n];
    int m2[m][n];
    int msum[m][n];
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            cin>>m1[i-1][j-1];
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            cin>>m2[i-1][j-1];
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            msum[i-1][j-1] = m1[i-1][j-1] + m2[i-1][j-1];
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            cout<<msum[i-1][j-1];
            if(j!=n){
                cout<<" ";
            }
        }
        cout<<endl;
    }
}