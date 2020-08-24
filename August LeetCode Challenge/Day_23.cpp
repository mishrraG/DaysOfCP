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
private:
	int sum(TreeNode* n, bool isLeft) {
		if (n == NULL)
			return 0;
		if (isLeft && n->left == NULL && n->right == NULL)
			return n->val;
		return sum(n->left, true) + sum(n->right, false);
	}

public:
	int sumOfLeftLeaves(TreeNode* root) {
		return sum(root, false);
	}
};