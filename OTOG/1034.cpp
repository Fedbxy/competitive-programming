#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    string s; getline(cin, s);

    int sum = 0;
    for (auto &e: s) {
        if (e >= '0' and e <= '9') sum += e - '0';
        else if (e >= 'A' and e <= 'Z') sum += e - 'A';
        else if (e >= 'a' and e <= 'z') sum -= e - 'a';
    }

    cout << sum;
    return 0;
}