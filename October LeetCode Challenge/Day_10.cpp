bool comp(pair<int, int> a, pair<int, int> b) {
	return a.second < b.second;
}
class Solution {
public:
	int findMinArrowShots(vector<vector<int>>& points) {
		int n = points.size();
		if (n == 0) {
			return 0;
		}
		vector<pair<int, int> >a;
		for (int i = 0; i < n; i++) {
			a.push_back({points[i][0], points[i][1]});
		}
		sort(a.begin(), a.end(), comp);
		int arrows = 1;
		int fin = a[0].second;
		if (n == 1) {
			return 1;
		}
		for (int i = 1; i < n; i++) {
			if (a[i].first <= fin) {
				continue;
			}
			else {
				arrows++;
				fin = a[i].second;
			}
		}
		return arrows;
	}
};