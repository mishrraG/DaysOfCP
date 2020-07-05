class Solution {
public:
	int hammingDistance(int x, int y) {
		int r = x ^ y;
		int setBits = 0;

		while (r > 0) {
			setBits += r & 1;
			r >>= 1;
		}

		return setBits;
	}
};