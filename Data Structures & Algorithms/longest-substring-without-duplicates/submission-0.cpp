class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<char> st;
        int i=0;
        int j=0;
        int maxLen = 0;
        while(j<s.length()) {
                        while(st.find(s[j]) != st.end()) {
                st.erase(s[i]);
                i++;
            }

            st.insert(s[j]);
            maxLen = max(maxLen, j-i+1);
            j++;
        }
        return maxLen;
    }
};
