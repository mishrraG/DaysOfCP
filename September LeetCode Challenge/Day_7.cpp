class Solution {
public:
	bool wordPattern(string pattern, string str) {
		vector<int> pat_map (26, 0);
		unordered_map<string, int> str_map;
		int i = 0, n = pattern.size();
		istringstream ss (str);
		string token;

		for (string token; ss >> token; ++i) {
			if (i == n || pat_map[pattern[i] - 'a'] != str_map[token])
				return false;
			pat_map[pattern[i] - 'a'] = str_map[token] = i + 1;
		}

		return i == n;
	}
};