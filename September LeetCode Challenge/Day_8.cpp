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
	static int sumRootToLeaf(const TreeNode* r, uint32_t sum = 0) {
		if (!r) return 0;
		sum |= r->val;
		if (!r->left && !r->right) return sum; // leaf
		sum <<= 1;
		return sumRootToLeaf(r->left, sum) + sumRootToLeaf(r->right, sum);
	}
};