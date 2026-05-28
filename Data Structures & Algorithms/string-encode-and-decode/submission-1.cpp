class Solution {
public:

    string encode(vector<string>& strs) {
        string final = "";
        for(int i=0;i<strs.size();i++) {
            int length  = strs[i].length();
            // cout<<"length: "<< length <<endl;
            string value = to_string(length);
            value += "+" + strs[i] + "#";
            final += value;
        }
        // cout<<final;
        return final;
    }

    vector<string> decode(string s) {
        vector<string> strs;
        for(int i=0;i<s.length();i++){
            if(s[i] == '#') continue;
            int length = 0;
            while(s[i]!='+') {
                int val = s[i] - '0';
                length = (length*10) + val;
                i++;
            }
            string st = "";
            for(int j=0;j<length;j++) {
                st += s[i+j+1];
            }
            strs.push_back(st);
            i += length+1;
        }
        return strs;
    }
};
