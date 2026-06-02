class Solution {
   public:
    int characterReplacement(string s, int k) {
        int i = 0;
        int j = 0;
        int maxElementCount = 0;
        // int maxElement = s[0];
        int maxLen = 0;
        map<char, int> mp;
        while (j < s.length()) {
            mp[s[j]]++;
            maxElementCount = max(maxElementCount, mp[s[j]]);
            if(j-i+1-maxElementCount<=k) {
                maxLen=max(maxLen, j-i+1);
            } else {
                while(j-i+1-maxElementCount > k) {
                    mp[s[i]]--;
                    // maxElementCount=0;
                    // for(auto itr:mp) {
                    //     maxElementCount = max(maxElementCount, itr.second);
                    // }
                    i++;
                }
            }
            j++;
        }
        return maxLen;
    }
};
