// written by poom
// score: 12/15
// this is NOT the solution to this problem

#include <bits/stdc++.h>
using namespace std;

queue<string> acc, wd;
string p[3];
int cou, c[3], d[3];

int main() {
    int n, m;
    string s;
    
    getline(cin, s);
    n = stoi(s);
    getline(cin, s);
    m = stoi(s);

    for (int i = 1; i <= n; i++) {
        getline(cin, s);
        acc.emplace(s);
    }

    for (int i = 1; i <= m; i++) {
        getline(cin, s);
        wd.emplace(s);
    }

    p[0] = p[1] = p[2] = "-";

    while (cou != n + m) {
        
        if (p[0] == "-" && !acc.empty()) {
            p[0] = acc.front();
            acc.pop();
            c[0] = 0;
            d[0] = 1;
        }
        else if (p[0] == "-" && !wd.empty()) {
            p[0] = wd.front();
            wd.pop();
            d[0] = 0;
            c[0] = 0;
        }
        if (p[1] == "-" && !acc.empty() && 2 * acc.size() > wd.size()) {
            p[1] = acc.front();
            acc.pop();
            c[1] = 0;
            d[1] = 1;
        }
        else if (p[1] == "-" &&  !wd.empty()) {
            p[1] = wd.front();
            wd.pop();
            c[1] = 0;
            d[1] = 0;
        }
        if (p[2] == "-" && !acc.empty() && 2 * acc.size() > wd.size()) {
            p[2] = acc.front();
            acc.pop();
            c[2] = 0;
            d[2] = 1;
        }
        else if (p[2] == "-" && !wd.empty()) {
            p[2] = wd.front();
            wd.pop();
            c[2] = 0;
            d[2] = 0;
        }

        for (int i = 0; i < 3; i++) {
            c[i]++;
        }

        bool ok = true;

        for (int i = 0; i < 3; i++) {
            if (d[i] == 0 && c[i] == 1) {
                ok = false;  
            }
            else if (d[i] == 1 && c[i] == 3) {
                ok = false;
            }
        }

        if (ok) {
            continue;
        }

        for (int i = 0; i < 3; i++) {
            if (d[i] == 0 && c[i] == 1) {
                cout << p[i] << "(w/d) ";
                p[i] = "-";
                cou++;   
            }
            else if (d[i] == 1 && c[i] == 3) {
                cout << p[i] << "(acc) ";
                p[i] = "-";
                cou++;
            }
            else {
                cout << "-(-) ";
            }
        }
        cout << "\n";
    }

    cout << "-(-) -(-) -(-) ";
}