class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> leftToRight(n,0);
        vector<int> rightToleft(n,0);
        leftToRight[0] = 1;
        rightToleft[n-1] = 1;
        for (int i = 1; i < n; i++) {
            leftToRight[i] = leftToRight[i - 1] * nums[i - 1];

            rightToleft[n - i - 1] =
                rightToleft[n - i] * nums[n - i];
        }

        vector<int> answer;
        for(int i=0;i<n;i++) {
            answer.push_back(leftToRight[i]*rightToleft[i]);
        }
        return answer;

    }
};
