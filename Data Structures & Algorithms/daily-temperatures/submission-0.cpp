class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        stack<pair<int,int>> st;
        vector<int> answer;

        for(int r = temp.size() - 1; r >= 0; r--) {

            while(!st.empty() && st.top().first <= temp[r]) {
                st.pop();
            }

            if(st.empty()) {
                answer.push_back(0);
            }
            else {
                answer.push_back(st.top().second - r);
            }

            st.push({temp[r], r});
        }

        reverse(answer.begin(), answer.end());
        return answer;
    }
};
