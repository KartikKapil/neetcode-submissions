class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> mp;
        int n = strs.size();
        for(int i=0;i<n;i++) {
            string st = strs[i];
            string sortedString = st;
            sort(sortedString.begin(), sortedString.end());
            if (mp.find(sortedString) != mp.end()) mp[sortedString].push_back(st);
            else mp[sortedString] = {st};
        }
        vector<vector<string>> ans;
        for(auto itr = mp.begin(); itr != mp.end(); itr++) {
            ans.push_back(itr->second);
        }
        return ans;
        
    }
};
