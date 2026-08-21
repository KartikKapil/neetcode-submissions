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
    string inOrderTree(TreeNode *root) {
        if(root==nullptr) return ".";
        return "$" + to_string(root->val) + inOrderTree(root->left) + inOrderTree(root->right);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        string s1 = inOrderTree(root);
        string s2 = inOrderTree(subRoot);

        if(s1.find(s2)!=std::string::npos) return true;
        return false;
    }
};
