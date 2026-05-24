class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;

        map<char, int> mp;

        for (char c : s) {
            mp[c]++;
        }

        for (char c : t) {
            if (mp.find(c) == mp.end()) return false;
            mp[c]--;
            if (mp[c] < 0) return false;
        }

        for (auto it = mp.begin(); it != mp.end(); ++it) {
            if (it->second != 0) return false;
        }

        return true;
    }
};