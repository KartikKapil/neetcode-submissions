class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++) {
            mp[nums[i]] = nums[i] + 1;
        }
        int maxlen = 0;
        for(auto itr = mp.begin();itr!=mp.end();itr++) {
            int currentValue = itr->first;
            int nextValue = itr->second;
            int intermediateLen = 1;
            while(mp.find(nextValue)!=mp.end()) {
                intermediateLen++;
                nextValue = mp[nextValue];
            }
            maxlen = max(maxlen, intermediateLen);
        }
        return maxlen;
        
    }
};
