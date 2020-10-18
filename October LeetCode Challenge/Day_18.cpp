class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if (n == 0 || n == 1 || k == 0) {
            return 0;
        }
        if (k >= n / 2) {
            int prof = 0;
            for (int i = 1; i < n; i++) {

                if (prices[i] > prices[i - 1])
                    prof += prices[i] - prices[i - 1];
            }
            return prof;
        }
        int dp[k + 1][n];
        memset(dp , 0 , sizeof(dp));
        for (int i = 1; i < k + 1; i++) {
            int maxprofitbefore  = INT_MIN;
            for (int j = 1; j < n; j++) {
                maxprofitbefore = max(maxprofitbefore , dp[i - 1][j - 1] - prices[j - 1]);
                dp[i][j] = max(dp[i][j - 1], prices[j] + maxprofitbefore);
            }
        }

        return dp[k][n - 1];
    }
};