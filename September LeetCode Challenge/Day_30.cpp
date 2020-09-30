class Solution {

public:

	int firstMissingPositive(vector<int>& nums) {


		if (nums.size() == 0) return 1;

		int n = nums.size();

		bool containsone = false;

		for (int i = 0; i < n; i++)
		{
			if (nums[i] == 1)
			{
				containsone = true;
				break;
			}
		}

		if (!containsone) return 1;

		for (int i = 0; i < nums.size(); i++)
		{
			if (nums[i] <= 0 or nums[i] > n)
			{
				nums[i] = 1;
			}
		}

		for (int i = 0; i < nums.size(); i++)
		{
			int val = nums[i];
			int pos = abs(val) - 1;

			if (nums[pos] > 0) nums[pos] = -1 * nums[pos];


		}


		for (int i = 0; i < nums.size(); i++)
		{
			if (nums[i] > 0)
			{
				return i + 1;
			}
		}


		return n + 1;




	}
};