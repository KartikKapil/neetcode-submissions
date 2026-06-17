class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int miniRate = 0;
        int maxRate = 0;
        int sumOfban = 0;
        int l = 0;
        int r = 0;
        for(auto x:piles) {
            sumOfban += x;
            maxRate = max(maxRate, x);
        }
        miniRate = ceil((double)sumOfban/h);
        // cout<< "sumOfban" << ceil(sumOfban/h) << "\n";
        // cout<< " minRate" << miniRate <<"\n";
        r =  maxRate - miniRate;
        sumOfban = 0;
        int ans ;
        // cout<< l << " " <<r;
        while(l<=r) {
            sumOfban = 0;
            int mid = l + (r-l)/2;
            int midValue = miniRate + mid;
            for(auto x:piles) {
            sumOfban += ceil((double)x/midValue);
            }
            if(sumOfban <= h) {
                r = mid - 1;
                ans = midValue;
                }
            else if(sumOfban > h) l = mid + 1;
        }
        return ans;
    }
};
