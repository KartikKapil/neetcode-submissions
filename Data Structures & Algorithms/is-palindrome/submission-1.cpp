class Solution {
public:
    bool isPalindrome(string s) {
        string updatedString = "";
       for (char c : s) {
            if (isalnum(c)) {
                updatedString += tolower(c);
            }
        }
        return updatedString == string(updatedString.rbegin(), updatedString.rend());
    }
};
