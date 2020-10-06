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
    TreeNode* insertIntoBST(TreeNode* root, int val, bool f = true) {
        if (!root) return new TreeNode(val);
        TreeNode* current = root;
        while (f)
            if (current->val < val)
                if (current->right)
                    current = current->right;
                else
                    current->right = new TreeNode(val), f = false;
            else if (current->left)
                current = current->left;
            else
                current->left = new TreeNode(val), f = false;
        return root;
    }
};