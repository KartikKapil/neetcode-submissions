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
    int findHeight(TreeNode* root) {
        if(!root) return 0;
        int lh = findHeight(root->left);
        int rh = findHeight(root->right);
        return 1+max(lh,rh);
    }
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        bool rb = isBalanced(root->right);
        bool lb = isBalanced(root->left);
        if(rb&&lb) {
            int fhl = findHeight(root->left);
            int rhl = findHeight(root->right);
            if(abs(fhl-rhl)<=1) return true;
        }
        return false;
    }
};
