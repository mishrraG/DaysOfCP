class Solution {
public:
    int helper(vector<int> &prices, int st, int n, bool bou, vector<vector<int> > &dp) {
        if (st >= n)
            return 0;
        if (dp[st][bou] != -1)
            return dp[st][bou];
        dp[st][bou] = max(helper(prices, st + 1 + bou, n, !bou, dp) + (bou * prices[st]) - (!bou * prices[st]),
                          helper(prices, st + 1, n, bou, dp));
        return dp[st][bou];
    }
    int maxProfit(vector<int>& prices) {
        int st = 0, n = prices.size();
        if (n == 0) return 0;
        vector<vector<int> > dp(n, vector<int> (2, -1));
        while ((st < (n - 1)) && (prices[st] > prices[st + 1]))
            st ++;
        return (st == (n - 1)) ? 0 : helper(prices, st, n, 1, dp) - prices[st];
    }
};