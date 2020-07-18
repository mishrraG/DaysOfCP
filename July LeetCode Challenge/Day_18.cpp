class Solution {
public:
    bool impossible;
    void dfs(vector<vector<int>>&map1, int i, vector<bool>&visited, vector<int>&donecourse) {
        if (visited[i]) {
            impossible = true;
            return;
        }
        visited[i] = true;
        if (map1[i].size() == 0) {
            donecourse.push_back(i);
            return;
        }
        else {
            for (auto it = map1[i].begin(); it != map1[i].end(); it++) {
                if (find(donecourse.begin(), donecourse.end(), *it) != donecourse.end())
                    continue;
                else {
                    dfs(map1, *it, visited, donecourse);
                    if (impossible) return;
                }
            }
            donecourse.push_back(i);
        }
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& courses) {
        impossible = false;
        vector<vector<int>>v(numCourses);
        vector<int>donecourse;
        vector<bool>visited(numCourses, false);
        for (auto it : courses) {
            v[it[0]].push_back(it[1]);
        }
        for (int i = 0; i < numCourses; i++) {
            if (!visited[i])
                dfs(v, i, visited, donecourse);
        }
        if (impossible) {
            vector<int>ans;
            return ans;
        }
        return donecourse;
    }
};