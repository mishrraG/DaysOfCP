class trieNode {
public:
	trieNode *left, *right;
};

void insertInTrie(trieNode *root, int num) {
	trieNode *curr = root;

	for (int i = 31; i >= 0; i--) {
		int bit = (num >> i) & 1;
		if (bit == 0) {
			if (!curr->left) {
				curr->left = new trieNode();
			}
			curr = curr->left;
		} else {
			if (!curr->right) {
				curr->right = new trieNode();
			}
			curr = curr->right;
		}
	}
}

class Solution {
public:
	int findMaximumXOR(vector<int>& nums) {
		trieNode *root = new trieNode();
		for (int curr : nums) {
			insertInTrie(root, curr);
		}
		int maxXor = INT_MIN;
		for (int no : nums) {
			trieNode *curr = root;
			int currXor = 0, value = no;

			for (int i = 31; i >= 0; i--) {
				int bit = (value >> i) & 1;
				if (bit == 0) {
					if (curr->right) {
						curr = curr->right;
						currXor += pow(2, i);
					} else {
						curr = curr->left;
					}
				} else {
					if (curr->left) {
						curr = curr->left;
						currXor += pow(2, i);
					} else {
						curr = curr->right;
					}
				}
			}
			if (currXor > maxXor)
				maxXor = currXor;
		}
		return maxXor;
	}
};