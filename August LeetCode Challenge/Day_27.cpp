// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
	int n, m;
	int rand10() {
		n = rand7(), m = 7;
		while (n > 5) {
			m = n - 5;
			n = rand7();
		}
		while (m == 7) m = rand7();
		return (m % 2 ? 5 : 0) + n;
	}
};