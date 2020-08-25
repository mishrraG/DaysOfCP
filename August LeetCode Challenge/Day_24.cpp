class Solution {
public:
	int mincostTickets(vector<int>& days, vector<int>& cost) {
		int n = days.size();
		int dp[n + 1];
		for (int i = 0; i <= n; i++)
			dp[i] = INT_MAX;
		dp[0] = 0;
		dp[1] = min(cost[0], min(cost[1], cost[2]));
		for (int i = 2; i <= n; i++)
		{
			dp[i] = dp[i - 1] + min(cost[0], min(cost[1], cost[2]));
			for (int j = 1; j < i; j++)
			{
				int d = days[i - 1] - days[j - 1] + 1;
				if (d <= 7)
					dp[i] = min(dp[i], dp[j - 1] + cost[1]);
				if (d <= 30)
					dp[i] = min(dp[i], dp[j - 1] + cost[2]);

			}
		}
		return dp[n];

	}
};