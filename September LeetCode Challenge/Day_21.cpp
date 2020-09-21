class Solution {
public:
	bool carPooling(vector<vector<int>>& trips, int capacity) {


		vector<int> timestamp(1001, 0);

		for (auto trip : trips)
		{
			timestamp[trip[1]] += trip[0];
			timestamp[trip[2]] -= trip[0];
		}

		int c = 0;

		for (auto number : timestamp)
		{
			c += number;
			if (c > capacity)
			{
				return false;
			}
		}

		return true;


	}
};