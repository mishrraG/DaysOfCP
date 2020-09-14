class Solution {
public:
	int rob(vector<int>& nums)
	{
		if  (nums.size() == 0)
			return 0;

		size_t evenHouses = 0;
		size_t oddHouses = 0;

		for (int i = 0; i < nums.size(); i++)
		{
			if (i % 2 == 0)
			{
				evenHouses += nums[i];
				evenHouses = evenHouses > oddHouses ? evenHouses : oddHouses;
			}
			else
			{
				oddHouses += nums[i];
				oddHouses = evenHouses > oddHouses ? evenHouses : oddHouses;
			}
		}

		return evenHouses > oddHouses ? evenHouses : oddHouses;
	}
};