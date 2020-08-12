class Solution {
public:
	vector<int> getRow(int rowIndex) {
		vector<int> row = {1}, prev;

		if (rowIndex == 0)
			return row;
		prev = row;
		row = {1, 1};
		if (rowIndex == 1)
			return row;
		for (int i = 2; i <= rowIndex; i++) {
			prev = row;
			row.clear();
			row.push_back(1);
			for (int j = 1; j < prev.size(); j++)
				row.push_back(prev[j] + prev[j - 1]);
			row.push_back(1);
		}
		return row;
	}
};