class Solution {
public:
	vector<int> findRightInterval(vector<vector<int>>& intervals) {
		unordered_map<int, int> m;
		vector<int> v;
		vector<int> ans;
		for (int i = 0 ; i < intervals.size(); i++) {
			m[intervals[i][0]] = i;
			v.push_back(intervals[i][0]);
		}
		sort(v.begin(), v.end());
		int end;
		for (int i = 0 ; i < intervals.size(); i++) {
			end = intervals[i][1];
			vector<int>::iterator it = lower_bound(v.begin(), v.end(), end);
			if (it != v.end()) {
				end = *it;
				ans.push_back(m[end]);
			} else {
				ans.push_back(-1);
			}
		}

		return ans;
	}
};