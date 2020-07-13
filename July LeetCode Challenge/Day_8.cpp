class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> output;
		sort(nums.begin(), nums.end());
		for (int i = 0; i < nums.size(); ++i) {
			// Never let i refer to the same value twice to avoid duplicates.
			if (i != 0 && nums[i] == nums[i - 1]) continue;
			int j = i + 1;
			int k = nums.size() - 1;
			while (j < k) {
				if (nums[i] + nums[j] + nums[k] == 0) {
					output.push_back({nums[i], nums[j], nums[k]});
					++j;
					// Never let j refer to the same value twice (in an output) to avoid duplicates
					while (j < k && nums[j] == nums[j - 1]) ++j;
				} else if (nums[i] + nums[j] + nums[k] < 0) {
					++j;
				} else {
					--k;
				}
			}
		}
		return output;
	}
};