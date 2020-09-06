class Solution {
public:
	int count(unsigned int num) {
		int cnt = 0;
		while (num) {
			cnt += (num & 1);
			num >>= 1;
		}
		return cnt;
	}

	int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
		int largest = 0;
		int n = A.size();
		vector<unsigned int> arrA(n);
		vector<unsigned int> arrB(n);
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				arrA[i] |= A[i][j] << (n - 1 - j);
				arrB[i] |= B[i][j] << (n - 1 - j);
			}
		}
		for (int s = 0; s < n; ++s) {
			for (int t = 0; t < n; ++t) {
				int cnt = 0;
				for (int i = s; i < n; ++i) {  /* A slides down s, right t */
					cnt += count((arrA[i - s] >> t) & arrB[i]);
				}
				largest = max(cnt, largest);
				cnt = 0;
				for (int i = 0; i < n - s; ++i) {  /* A slides up s, left t */
					cnt += count(arrB[i] & (arrA[i + s] << t));
				}
				largest = max(cnt, largest);
			}
		}
		return largest;
	}
};