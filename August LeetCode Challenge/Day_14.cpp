class Solution {
public:
    int longestPalindrome(string s)
    {
        vector<int>v(255, 0);
        int ans = 0;
        for (int i = 0; i < s.size(); i++)
        {
            v[s[i] - 'A']++;
            if (!(v[s[i] - 'A'] % 2))
                ans += 2;
        }
        return s.size() > ans ? ans + 1 : ans;

    }
};