class Solution {
public:
	vector<vector<int>> verticalTraversal(TreeNode* root) {
		if (root == NULL) {
			return {};
		}

		map<pair<int, int>, set<int>> map;
		int maxValue = INT_MIN;
		int minValue = INT_MAX;
		dfs(map, root, 0, 0, maxValue, minValue);
		vector<vector<int>> result(maxValue - minValue + 1);
		for (const auto& pair : map) {
			int index = pair.first.first - minValue;
			result[index].insert(result[index].end(), pair.second.begin(), pair.second.end());
		}
		return result;
	}

	void dfs(map<pair<int, int>, set<int>>& map, TreeNode* root, int x, int y, int& maxValue, int& minValue) {
		if (root == NULL) {
			return;
		}
		map[ {x, y}].insert(root->val);
		maxValue = max(maxValue, x);
		minValue = min(minValue, x);
		dfs(map, root->left, x - 1, y + 1, maxValue, minValue);
		dfs(map, root->right, x + 1, y + 1, maxValue, minValue);
	}

};