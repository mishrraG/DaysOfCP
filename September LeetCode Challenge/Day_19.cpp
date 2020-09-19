class Solution {
public:
	vector<int> sequentialDigits(int low, int high) {
		string s = "123456789";
		vector<int> v;
		for (int i = 0; i < s.length(); i++)
		{
			for (int j = i; j < s.length(); j++)
			{
				string sub = s.substr(i, j - i + 1);

				int ans = stoi(sub);

				if (ans >= low and ans <= high)
				{
					v.push_back(ans);
				}
			}
		}
		sort(v.begin(), v.end());
		return v;
	}
};