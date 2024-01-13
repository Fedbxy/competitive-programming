// written by poom
// score: 15/15

#include <bits/stdc++.h>
using namespace std;

const int MxA = 1e2 + 1;
const int MxN = 2e2 + 1;
int a, now, state, n, x[MxN], y[MxN], inq[MxN];

int main() {
    //cin.tie(nullptr)->ios_base::sync_with_stdio(false);

    cin >> a >> now >> state >> n;

    for (int i = 1; i <= n; i++) {
        cin >> x[i] >> y[i];
    }

    while (true) {
        bool ok = true;
        for (int i = 1; i <= n; i++) {
            if (!inq[i] && now == x[i] && state == y[i]) {
                cout << now;
                if (state == 1) {
                    cout << "u";
                }
                else {
                    cout << "d";
                }
                cout << " ";
                inq[i] = 1;
            }
            if (!inq[i]) {
                ok = false;
            }
        }

        if (ok) {
            return 0;
        }
        
        if (now == 0 || now == a + 1) {
            state = 1 - state;      
        }
        
        if (state == 1) {
            now++;
        }
        else {
            now--;
        }
    }
}

/*
10
3 1
10
4 1
5 0
3 1
3 0
5 1
2 1
10 0
7 0
9 1
2 0
*/