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
    vector<int> helper(TreeNode* root) {
        vector<int> out = {0, 0};
        if (root == nullptr)
            return out;
        vector<int> left = helper(root->left);
        vector<int> right = helper(root->right);
        out[0] = root->val + left[1] + right[1];
        out[1] = max(left[0], left[1]) + max(right[0], right[1]);
        return out;
    }
    
    int rob(TreeNode* root) {
        vector<int> out = helper(root);
        return max(out[0], out[1]);
    }
};
