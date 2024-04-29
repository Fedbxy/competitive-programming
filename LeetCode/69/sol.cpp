class Solution {
public:
    int mySqrt(int x) {
        if(x == 0 or x == 1) return x;
        
        int l = 0, r = x;
        while(l < r) {
            int mid = l + (r - l) / 2;
            if(1LL * mid * mid > 1LL * x) r = mid;
            else l = mid + 1;
        }
        return r - 1;
    }
};