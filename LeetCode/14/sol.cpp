class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = strs[0];
        for(int i=1;i<strs.size();++i) {
            string s = strs[i];
            string temp;
            for(int j=0;j<min(s.size(), ans.size());++j) {
                if(ans[j] == s[j]) temp.push_back(s[j]);
                else {
                    ans = temp;
                    break;
                }
            }
            ans = temp;
        }
        return ans;
    }
};