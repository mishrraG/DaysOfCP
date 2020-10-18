class Solution {

public:

	vector<string> findRepeatedDnaSequences(string s) {

		vector<string> v;

		unordered_map<string, int> mp;

		if (s.length() <= 10)
		{
			return v;
		}

		for (int i = 0; i <= s.length() - 10; i++)
		{
			mp[s.substr(i, 10)]++;
		}

		for (auto x : mp)
		{
			if (x.second > 1)
			{
				v.push_back(x.first);
			}
		}

		return v;
	}
};