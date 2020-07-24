class Solution {
public:
    void dfs(vector<vector<int>> &graph, vector<vector<int>> &ans, int start, int dest, vector<int> &v) {
        v.push_back(start);
        if (start == dest) {
            ans.push_back(v);
            v.pop_back();
            return;
        }
        for (int x : graph[start]) {
            dfs(graph, ans, x, dest, v);
        }
        v.pop_back();
        return;
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int> > ans;
        vector<int> v;
        int n = graph.size();
        dfs(graph, ans, 0, n - 1, v);
        return ans;
    }
};