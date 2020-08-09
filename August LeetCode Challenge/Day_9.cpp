class Solution {
public:
	int orangesRotting(vector<vector<int>>& grid) {
		int count = 0, iter = -1;
		vector<vector<int>>grid2 = grid;
		do
		{

			iter++;
			count = 0;
			for (int i = 0; i < grid.size(); i++)
			{
				for (int j = 0; j < grid[0].size(); j++)
				{
					if (grid[i][j] == 2)
					{
						if (i > 0 && grid[i - 1][j] == 1)
						{
							grid2[i - 1][j] = 2;
							count++;
						}
						if (i < grid.size() - 1 && grid[i + 1][j] == 1)
						{
							grid2[i + 1][j] = 2;
							count++;
						}

						if (j > 0 && grid[i][j - 1] == 1)
						{
							grid2[i][j - 1] = 2;
							count++;
						}

						if (j < grid[0].size() - 1 && grid[i][j + 1] == 1)
						{
							grid2[i][j + 1] = 2;
							count++;
						}

					}
				}
			}
			grid = grid2;



		} while (count != 0);

		for (int i = 0; i < grid.size(); i++)
		{
			for (int j = 0; j < grid[0].size(); j++)
			{
				if (grid[i][j] == 1)
				{
					iter = -1;
					break;

				}
			}
		}

		return iter;
	}
};