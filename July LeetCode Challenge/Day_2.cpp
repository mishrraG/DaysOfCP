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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int> > result;
        vector<int> level;
        queue<TreeNode*> myQueue;
        if (root == NULL)
            return result;
        myQueue.push(root);
        int currentLevelNodeNum = 1;
        int nextLevelNodeNum = 0;
        while (!myQueue.empty()) {
            TreeNode* temp = myQueue.front();
            myQueue.pop();
            level.push_back(temp->val);
            currentLevelNodeNum--;
            if (temp->left != NULL) {
                myQueue.push(temp->left);
                nextLevelNodeNum++;
            }
            if (temp->right != NULL) {
                myQueue.push(temp->right);
                nextLevelNodeNum++;
            }
            if (currentLevelNodeNum == 0) {
                result.push_back(level);
                level.clear();
                currentLevelNodeNum = nextLevelNodeNum;
                nextLevelNodeNum = 0;
            }
        }
        vector<vector<int> > final;
        for (int i = result.size() - 1; i >= 0; i--) {
            final.push_back(result[i]);
        }
        return final;

    }
};