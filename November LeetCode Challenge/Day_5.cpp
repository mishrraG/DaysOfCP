class Solution {
public:
	int minCostToMoveChips(vector<int>& position) {
		short oddNumbers = 0, evenNumbers = 0;
		for (std::vector<int>::iterator it = position.begin(); it != position.end(); ++it)
		{
			if (*it % 2 == 0)
			{
				++evenNumbers;
			}
			else
			{
				++oddNumbers;
			}
		}
		if (oddNumbers >= evenNumbers)
		{
			return evenNumbers;
		}
		return oddNumbers;
	}
};