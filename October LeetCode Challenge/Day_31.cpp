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

    void fun(TreeNode* root, TreeNode*&first, TreeNode*&mid, TreeNode*&last, TreeNode*&prev)
    {
        if (!root)
            return;
        fun(root->left, first, mid, last, prev);
        if (prev && root->val < prev->val)
        {
            if (!first)
            {
                first = prev;
                mid = root;
            }
            else last = root;
        }
        prev = root;
        fun(root->right, first, mid, last, prev);
    }

    void recoverTree(TreeNode* root) {
        if (!root)
            return ;
        TreeNode* first = NULL, *last = NULL, *mid = NULL, *prev = NULL;
        fun(root, first, mid, last, prev);
        if (last)
            swap(last->val, first->val);

        else swap(first->val, mid->val);
    }
};