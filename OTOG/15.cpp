#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n; cin >> n;
    while(n--) {
        int top = 1, front = 2, left = 3, back = 5, right = 4, bottom = 6;
        string s; cin >> s;
        for(auto e:s) {
            if(e == 'F') {
                int temp = top;
                top = back;
                back = bottom;
                bottom = front;
                front = temp;
            } else if(e == 'B') {
                int temp = top;
                top = front;
                front = bottom;
                bottom = back;
                back = temp;
            } else if(e == 'L') {
                int temp = top;
                top = right;
                right = bottom;
                bottom = left;
                left = temp;
            } else if(e == 'R') {
                int temp = top;
                top = left;
                left = bottom;
                bottom = right;
                right = temp;
            } else if(e == 'C') {
                int temp = front;
                front = right;
                right = back;
                back = left;
                left = temp;
            } else {
                int temp = front;
                front = left;
                left = back;
                back = right;
                right = temp;
            }
        }
        cout << front << ' ';
    }
    cout << '\n';
    return 0;
}