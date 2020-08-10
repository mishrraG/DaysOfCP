class Solution {
public:
	int titleToNumber(string s) {
		int ans = 0, n = s.length() - 1;
		for (int i = n; i >= 0; i--)
			ans += pow(26, n - i) * (s[i] - 'A' + 1);
		return ans;
	}
};