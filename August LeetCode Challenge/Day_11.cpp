class Solution {
public:
	int hIndex(vector<int>& citations) {
		unordered_map<int, int> m;
		int maxi = INT_MIN;
		for (int i = 0; i < citations.size(); i++) {
			maxi = max(maxi, citations[i]);
			m[citations[i]]++;
		}
		int cnt = 0;
		for (int i = maxi; i >= 0; i--) {
			if (m.count(i))cnt += m[i];
			if (cnt >= i)return i;
		}
		return 0;
	}
};