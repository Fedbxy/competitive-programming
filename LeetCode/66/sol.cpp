class Solution {
public:
    vector<int> plusOne(vector<int>& arr) {
        reverse(arr.begin(), arr.end());

        int tmp = 1;
        for (int i = 0; i < arr.size(); ++i) {
            arr[i] += tmp;
            if (arr[i] >= 10) arr[i] -= 10;
            else tmp = 0;
        }
        if (tmp) arr.emplace_back(tmp);

        reverse(arr.begin(), arr.end());
        return arr;
    }
};