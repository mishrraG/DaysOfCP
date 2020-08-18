class Solution {
public:
    vector<int> bfs(int N, int K, vector<int> &ans)
    {
        queue<int> q;
        for (int i = 1; i < 10; i++)
        {
            q.push(i);
        }
        int lvl = 1;
        while (!q.empty())
        {
            int n = q.size();
            while (n--)
            {
                int t1 = q.front();
                q.pop();
                if (lvl == N)
                {
                    ans.push_back(t1);
                    continue;
                }
                int t = t1 % 10;
                int n1 = t - K;
                int n2 = t + K;
                if (n1 >= 0 && n1 < 10)
                {
                    q.push(t1 * 10 + n1);
                }
                if (K != 0 && n2 >= 0 && n2 < 10)
                {
                    q.push(t1 * 10 + n2);
                }
            }
            lvl++;
        }
        return ans;
    }
    vector<int> numsSameConsecDiff(int N, int K) {
        vector<int> ans;
        if (N == 1)
        {
            for (int i = 0; i < 10; i++)
            {
                ans.push_back(i);
            }
            return ans;
        }
        return bfs(N, K, ans);
    }
};