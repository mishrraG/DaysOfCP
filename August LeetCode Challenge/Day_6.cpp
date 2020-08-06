class Solution {
public:
	vector<int> findDuplicates(vector<int>& nums) {
		map<int, int>mp;
		for (auto i : nums)
		{
			mp[i]++;
		}
		vector<int>res;
		for (auto m : mp)
		{
			if (m.second == 2) {
				res.push_back(m.first);
			}
		}
		return res;
	}
};