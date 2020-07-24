class Solution {
public:
	vector<int> singleNumber(vector<int>& nums) {
		int x = 0;
		for (const int curr : nums) {
			x ^= curr;
		}
		int bit;
		for (int i = 0; i < 32; ++i) {
			if (x & (1 << i)) {
				bit = i;
				break;
			}
		}
		int first = 0;
		for (int a : nums) {
			if (a & (1 << bit)) {
				first ^= a;
			}
		}
		int second = first ^ x;
		return {first, second};
	}
};