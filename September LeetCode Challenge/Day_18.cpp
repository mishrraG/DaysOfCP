class Solution {
public:
	int maxProfit(vector<int>& prices) {
		if (prices.size() < 1) return 0;
		int mp = INT_MIN;
		vector<int> minUntil(prices.size(), 0);
		minUntil[0] = prices[0];
		for (int i = 1; i < prices.size(); i++) {
			minUntil[i] = min(minUntil[i - 1], prices[i]);
			mp = max(mp, prices[i] - minUntil[i]);
		}
		mp = max(mp, prices.front() - minUntil.front());
		return mp;
	}
};