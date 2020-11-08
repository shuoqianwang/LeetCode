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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> out;
        if (!root)
            return out;
        queue<TreeNode*> level;
        level.push(root);
        level.push(nullptr);
        TreeNode* prev;
        while (!level.empty()) {
            TreeNode* cur = level.front();
            level.pop();
            if (cur != nullptr) {
                prev = cur;
                if (cur->left)
                    level.push(cur->left);
                if (cur->right)
                    level.push(cur->right);
            } else {
                out.push_back(prev->val);
                if (!level.empty())
                    level.push(nullptr);
            }
        }
      return out;
    }
};
