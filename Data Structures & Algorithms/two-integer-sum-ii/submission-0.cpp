class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0;
        int right = numbers.size() - 1;
        vector<int> answer;
        while(left<right) {
            int val = numbers[left]+numbers[right];
            if( val == target) {
                answer.push_back(left+1);
                answer.push_back(right+1);
                break;
            } else if (val<target) {
                left++;
            } else {
                right--;
            }
        }
        return answer;
    }
};

// explanation soacho 
// [1,2,3,4,5,6,7,8,9]
// 
