#include <bits/stdc++.h>

using namespace std;

bool check(string& s, int i, int j) {
    if (i >= j) return true;
    if (s[i] != s[j]) return false;
    return check(s, i + 1, j - 1);
}

int main() {
    char tmp[100001]; scanf("%s", tmp);
    string s; s = string(tmp);
    check(s, 0, s.size() - 1) ? printf("yes") : printf("no");
    return 0;
}