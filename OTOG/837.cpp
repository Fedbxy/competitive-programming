#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n; cin >> n;
    // ----------------------------------------
    for(int i=0;i<3;i++) {
        for(int j=0;j<n;j++) cout << "#";
        cout << " ";
    }
    for(int j=0;j<n-1;j++) cout << "#";
    cout << "\n";
    // ----------------------------------------
    string s;
    s = "#";
    for(int j=0;j<n;j++) s.push_back(' ');

    for(int i=0;i<3;i++) {
        s += "#";
        for(int j=0;j<n-2;j++) s.push_back(' ');
        s += (i == 2 ? "#\n" : "# ");
    }

    for(int i=0;i<n-2;i++) cout << s;
    // ----------------------------------------
    for(int i=0;i<2;i++) {
        for(int j=0;j<n;j++) cout << "#";
        
        cout << " #";
        for(int j=0;j<n-2;j++) cout << " ";
        cout << "#";
        cout << (i == 0 ? " " : "\n");
    }
    // ----------------------------------------
    string s2;
    s = "#";
    for(int j=0;j<n;j++) s.push_back(' ');

    s += "#";
    for(int j=0;j<n-2;j++) s.push_back(' ');
    s += "# #";

    s2 = "#";
    for(int j=0;j<n-2;j++) s2.push_back(' ');
    s2 += "#\n";

    for(int i=0;i<n-2;i++) {
        cout << s;

        for(int j=0;j<i;j++) cout << " ";
        cout << "# ";
        for(int j=0;j<n-i-2;j++) cout << " ";

        cout << s2;
    }
    // ----------------------------------------
    cout << "#";
    for(int j=0;j<n;j++) cout << " ";

    for(int j=0;j<n;j++) cout << "#";

    cout << " #";
    for(int j=0;j<n-2;j++) cout << " ";
    cout << "# ";

    for(int j=0;j<n-2;j++) cout << "#";
    cout << "#\n";

    return 0;
}