class Solution {
public:
    static bool comp(pair<int,int> &a, pair<int,int> &b) {
        return a.first > b.first;
    }

    int carFleet(int target, vector<int>& position, vector<int>& speed) {

        vector<pair<int,int>> vt;

        for(int i=0;i<position.size();i++) {
            vt.push_back({position[i], speed[i]});
        }

        sort(vt.begin(), vt.end(), comp);

        stack<double> st;

        for(int i=0;i<vt.size();i++) {

            double timeToReach =
                (double)(target - vt[i].first) / vt[i].second;

            if(st.empty() || timeToReach > st.top()) {
                st.push(timeToReach);
            }
        }

        return st.size();
    }
};