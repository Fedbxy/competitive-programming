#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(auto e: s) {
            if(e == '(' or e == '{' or e == '[') st.push(e);
            else if(!st.empty()) {
                char c = st.top();
                if(e == ')' and c == '(') st.pop();
                else if(e == '}' and c == '{') st.pop();
                else if(e == ']' and c == '[') st.pop();
                else {
                    return false;
                }
            } else {
                return false;
            }
        }
        if(!st.empty()) return false;
        return true;
    }
};