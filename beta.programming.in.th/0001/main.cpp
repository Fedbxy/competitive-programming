#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    
    int a,b,c;

    cin>>a>>b>>c;

    int score = a+b+c;
    string grade;

    if (score<=100 && score>=80){
        grade = "A";
    }else if(score>=75){
        grade = "B+";
    }else if(score>=70){
        grade = "B";
    }else if(score>=65){
        grade = "C+";
    }else if(score>=60){
        grade = "C";
    }else if(score>=55){
        grade = "D+";
    }else if(score>=50){
        grade = "D";
    }else{
        grade = "F";
    }

    cout<<grade<<endl;
}