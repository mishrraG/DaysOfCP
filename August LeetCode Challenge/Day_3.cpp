class Solution {
public:
	bool isPalindrome(string s)
	{
		int l = 0;
		int r = s.size() - 1;
		while (l < r)
		{
			if (isalnum(s[l]) && isalnum(s[r]))
			{
				if (tolower(s[l]) != tolower(s[r]))
					return false;
				else
				{
					l++; r--;
					continue;
				}
			}
			else
			{

				if (!isalnum(s[l]))
					l++;
				if (!isalnum(s[r]))
					r--;
			}
		}
		return true;

	}
};
