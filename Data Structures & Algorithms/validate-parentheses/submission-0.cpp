class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(char ch:s) {
            if(ch == '[' || ch == '{' || ch == '(') st.push(ch);
            else if( ch == ']' ) {
                if(st.empty()) return false;
                char top = st.top();
                if(top != '[') return false;
                st.pop();
            } else if (ch == ')' ) {
                if(st.empty()) return false;
                char top = st.top();
                if(top != '(') return false;
                st.pop();
            } else if (ch == '}') {
                if(st.empty()) return false;
                char top = st.top();
                if(top != '{') return false;
                st.pop();
            }
        }
        if(st.empty()) return true;
        return false;
    }
};
