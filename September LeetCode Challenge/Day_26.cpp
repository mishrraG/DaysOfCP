class Solution {
public:
	int findPoisonedDuration(vector<int>& timeseries, int duration) {
		if (timeseries.size() == 0)  return 0;
		int count = 0;

		for (int i = 1; i < timeseries.size(); i++)
		{
			if (timeseries[i] - timeseries[i - 1] >= duration)
			{
				count += duration;
			}
			else
			{
				count += timeseries[i] - timeseries[i - 1];
			}
		}
		count += duration;
		return count;

	}
};