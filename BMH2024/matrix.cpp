// written by poom
// score: 5/5

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
char ch;

int main() {
    int a, b, c, d;
    cin >> a >> ch >> b;

    int A[a + 1][b + 1];
    for (int i = 1; i <= a; i++) {
        for (int j = 1; j <= b; j++) {
            cin >> A[i][j] >> ch;
        }
        cin >> ch;
    }

    cin >> ch >> c >> ch >> d;

    int B[c + 1][d + 1];
    for (int i = 1; i <= c; i++) {
        for (int j = 1; j <= d; j++) {
            cin >> B[i][j] >> ch;
        }
        cin >> ch;
    }

    int total;
    for (int i = 1; i <= a; i++) {
        for (int j = 1; j <= d; j++) {
            total = 0;
            for (int k = 1; k <= b; k++) {
                total += A[i][k] * B[k][j];
            }
            cout << total << " ";
        }
        cout << "\n";
    }
}