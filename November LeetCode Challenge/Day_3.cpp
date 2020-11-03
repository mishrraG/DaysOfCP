class Solution {
public:
    int maxPower(string s)
    {
        int c = 1, m = 1, n = s.length();
        for (int i = 1; i < n; i++)
        {
            if (s[i] == s[i - 1])
            {
                c++;
                m = max(m, c);
            }
            else c = 1;
        }
        return m;
    }
};