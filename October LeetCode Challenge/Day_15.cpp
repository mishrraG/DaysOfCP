class Solution {
public:
	void rotate(vector<int>& nums, int k) {
		k = k % nums.size();
		vector<int> temp(k);

		int j = 0;
		for (int i = nums.size() - k; i < nums.size(); i++) {
			temp[j++] = nums[i];
		}

		j = nums.size() - 1;

		for (int i = nums.size() - k - 1; i >= 0; i--) {
			nums[j--] = nums[i];
		}


		for (int i = 0; i < k; i++) {
			nums[i] = temp[i];
		}
	}
};