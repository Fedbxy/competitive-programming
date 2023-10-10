#include <bits/stdc++.h>

using namespace std;

bool isPrime(int a){
    if(a==1){
        return false;
    }
    for(int i=2;i<=sqrt(a);i++){
        if(a%i==0){
            return false;
        }
    }
    return true;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int a,b;cin>>a>>b;
    int count=0;
    map<vector<int>,bool> processed;
    for(int i=a;i<=b;i++){
        for(int j=a;j<=b;j++){
            for(int k=a;k<=b;k++){
                vector<int> temp={i,j,k};
                sort(temp.begin(),temp.end());
                if(processed.find(temp)==processed.end()){
                    if(isPrime(i+j+k)){
                        count++;
                        processed[temp]=true;
                    }else{
                        processed[temp]=false;
                    }
                }
            }
        }
    }
    cout<<count<<"\n";
    return 0;
}