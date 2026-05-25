class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int minLen = strs[0].size();
for (int i = 1; i < strs.size(); i++) {
    minLen = min(minLen, (int)strs[i].size());
}
        string answer = "";
        for(int i=0;i<minLen;i++) {
            bool flag=false;
            for(int j=0;j<strs.size();j++) {
                if(strs[j][i]!=strs[0][i]) flag = true;
            }
            if(flag) break;
            answer = answer + strs[0][i];
        } 
        return answer;
    }
};