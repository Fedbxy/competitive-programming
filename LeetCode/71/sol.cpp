#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    vector<string> split(string s) {
        vector<string> ans;
        int l, r = -1;
        do {
            l = r + 1;
            r = s.find("/", l);
            ans.emplace_back(s.substr(l, r - l));
        } while (r != -1);
        return ans;
    }
public:
    string simplifyPath(string path) {
        stack<string> s;
        vector<string> tmp = split(path);

        for (auto& e: tmp) {
            if (!e.empty() && e != ".") {
                if (e == "..") {
                    if (!s.empty()) s.pop();
                    continue;
                }
                s.emplace(e);
            }
        }

        vector<string> rev;
        while(!s.empty()) {
            rev.emplace_back(s.top());
            s.pop();
        }
        reverse(rev.begin(), rev.end());
        string ans = "/";
        for (int i = 0; i < rev.size(); ++i) ans.append(rev[i] + (i == rev.size() - 1 ? "" : "/"));
        return ans;
    }
};