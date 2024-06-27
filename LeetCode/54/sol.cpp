#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<bool>> flag(n + 2, vector<bool> (m + 2, true));
        vector<int> ans;

        for (int i = 1; i <= n; ++i) for (int j = 1; j <= m; ++j) flag[i][j] = false;

        int ui = 1, uj = 0, di = 0, dj = 1;
        while (true) {
            flag[ui][uj] = true;

            int vi = ui + di, vj = uj + dj;
            if (flag[vi][vj]) {
                if (dj == 1) di = 1, dj = 0;
                else if (di == 1) di = 0, dj = -1;
                else if (dj == -1) di = -1, dj = 0;
                else if (di == -1) di = 0, dj = 1;
                vi = ui + di, vj = uj + dj;
                if (flag[vi][vj]) {
                    break;
                }
            }

            ans.push_back(matrix[vi - 1][vj - 1]);
            ui = vi, uj = vj;
        }

        return ans;
    }
};