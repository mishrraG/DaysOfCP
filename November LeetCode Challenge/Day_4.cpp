class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& e) {
        vector<vector <int> > g(n);
        vector <int> deg(n, 0);
        if (e.size() == 0)
        {
            return {0};
        }
        for (int i = 0; i < e.size(); i++)
        {
            g[e[i][0]].push_back(e[i][1]);
            g[e[i][1]].push_back(e[i][0]);
            deg[e[i][1]]++;
            deg[e[i][0]]++;
        }
        queue <int> q;
        for (int i = 0; i < n; i++)
        {
            if (deg[i] == 1)
            {
                q.push(i);
            }
        }
        while (n > 2)
        {
            int sz = q.size();
            n = n - q.size();
            for (int i = 0; i < sz; i++)
            {
                int t = q.front();
                q.pop();
                for (int j = 0; j < g[t].size(); j++)
                {
                    deg[g[t][j]]--;
                    if (deg[g[t][j]] == 1)
                    {
                        q.push(g[t][j]);
                    }
                }
            }
        }
        vector <int> ans;
        while (!q.empty())
        {
            ans.push_back(q.front());
            q.pop();
        }
        return ans;
    }
};