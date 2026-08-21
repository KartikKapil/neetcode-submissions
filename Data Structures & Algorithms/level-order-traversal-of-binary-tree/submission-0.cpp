/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == nullptr) return {};
        queue<pair<TreeNode*,int>> q;
        vector<vector<int>> ans;
        q.push({root, 0});
        while(!q.empty()) {
            int currentLevelSize = q.size();
            vector<int> intermAns = {};
            for(int i=0; i<currentLevelSize;i++) {
                pair<TreeNode*,int> p = q.front();
                q.pop();
                TreeNode* currentNode = p.first;
                int currentLevel = p.second;
                intermAns.push_back(currentNode->val);
                if(currentNode->left!=nullptr) q.push({currentNode->left, currentLevel+1});
                if(currentNode->right!=nullptr) q.push({currentNode->right, currentLevel+1});
            }
            ans.push_back(intermAns);
        }
        return ans;
    }
};
