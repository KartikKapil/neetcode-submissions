class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int xorGate = 0;
        for(int i = 0;i<nums.size();i++) {
            xorGate = xorGate ^ nums[i];
        }
        return xorGate;
    }
};
