class Solution {
public:
	int eraseOverlapIntervals(vector<vector<int>>& intervals) {
		if (intervals.empty()) return 0;
		sort(begin(intervals), end(intervals));
		vector<int>prev = intervals[0], cur;
		int ans = 0;
		for (int i = 1 ; i < intervals.size() ; i++)
		{
			cur = intervals[i];
			if (cur[0] < prev[1])
			{
				ans++;
				if (cur[1] <= prev[1]) prev = cur;
			}
			else prev = cur;
		}
		return ans;
	}
};