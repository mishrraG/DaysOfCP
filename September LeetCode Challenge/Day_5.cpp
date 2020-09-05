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

	void traverse(TreeNode *root, map<int, int> & mm) {
		if (!root) {
			return;
		}

		else {
			mm[root->val]++;
			traverse(root->left, mm);
			traverse(root->right, mm);
		}

	}


	vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
		vector<int> ans;

		map<int, int> mm;

		traverse(root1, mm);
		traverse(root2, mm);

		for (auto x : mm) {
			int cou = x.second;
			int ele = x.first;
			while (cou--) {
				ans.push_back(ele);
			}
		}

		return ans;
	}
};