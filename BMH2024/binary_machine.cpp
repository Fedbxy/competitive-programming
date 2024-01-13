// written by fed
// score: 3/15
// this is NOT the solution to this problem

#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    string s1,s2;cin>>s1>>s2;
    long long num1=stoll(s1, 0, 2),num2=stoll(s2, 0, 2);
    int num = num1+num2;
    if(num%2==0) num--;
    cout<<bitset<128>(num).to_string().substr(128 - (int)(log2(num)) - 1)<<'\n';
    return 0;
}