class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int currVal = INT_MIN;
        int currCount = 0;
        for(int i=0;i < nums.size(); i++) {
            if(currVal != nums[i]) {
                if(currCount == 0) {
                    currVal = nums[i];
                    currCount = 1;
                }
                else currCount--;
            } else currCount++;
        }
        return currVal;
    }
};