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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.size() == 0) return NULL;
        unordered_map<int, int> in_idx;
        for (int i = 0; i < inorder.size(); ++i) {
            in_idx[inorder[i]] = i;
        }
        int root_idx = postorder.size() - 1;
        return build(inorder, postorder, in_idx, 0, inorder.size() - 1, root_idx);
    }

private:
    TreeNode* build(vector<int>& inorder, vector<int>& postorder,
                    unordered_map<int, int>& in_idx, int in_l, int in_r, int& root_idx) {
        if (in_l > in_r) return NULL;
        TreeNode* node = new TreeNode(postorder[root_idx]);
        --root_idx;
        if (in_l == in_r) return node;
        int in_root_idx = in_idx[node->val];
        node->right = build(inorder, postorder, in_idx, in_root_idx + 1, in_r, root_idx);
        node->left = build(inorder, postorder, in_idx, in_l, in_root_idx - 1, root_idx);
        return node;
    }
};