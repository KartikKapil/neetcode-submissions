class Solution {
public:
    int maxArea(vector<int>& heights) {
        int i = 0;
        int j = heights.size() - 1;
        int maxAreaVal = 0;
        while(i<j) {
            maxAreaVal = max(maxAreaVal,((j - i) * min(heights[i],heights[j])));
            if(heights[i]<heights[j]) i++;
            else j--;
        }     
        return maxAreaVal;
    }
};
// right [1,6,2,4,3,6,3,6]
// left []