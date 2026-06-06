class Solution {
public:

    int convertToInt(string s) {
        int i = 0;
        bool isNegtive = false;
        for(char ch: s) {
            if(ch=='-') {
                isNegtive = true;
                continue;
            }
            int curr = ch - '0';
            i = (i*10) + curr;
        }
        if(isNegtive) i = i*-1;
        return i;
    }

    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(string s: tokens) {
            if(s=="+" ||
               s=="-" ||
               s=="*" ||
               s=="/" ) {
                int value1 = st.top();
                st.pop(); 
                int value2 = st.top();
                st.pop();
                int value3;
                if(s=="+") value3 = value1+value2;
                if(s=="-")value3 = value2-value1;
                if(s=="*")value3 = value1*value2;
                if(s=="/")value3 = (int)floor(value2/value1);
                st.push(value3);
               }
               else {
                int value = convertToInt(s);
                st.push(value);
               }
        }
        return st.top();
        
    }
};
