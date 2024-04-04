#include <bits/stdc++.h>

using namespace std;

multiset<int> s;

bool usePakpim(int x) {
    bool val = false;
    if (s.find(x) != s.end()) val = true;
    s.insert(x);
	return val;
}

int usePeteza() {
    if (!s.empty()) {
        int val = *s.rbegin();
        s.erase(s.find(val));
        return val;
    }
	return INT_MAX;
}

int useBlackslex() {
    if (!s.empty()) {
        int val = *s.begin();
        s.erase(s.begin());
        return val;
    }
	return INT_MIN;
}