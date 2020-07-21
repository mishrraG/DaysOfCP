class Solution {
public:
	string addBinary(string a, string b) {
		int n1 = a.size() - 1;
		int n2 = b.size() - 1;
		int carry = 0;
		int sum = 0;
		string s;
		while (n1 >= 0 || n2 >= 0) {
			int c1 = n1 >= 0 ? a[n1] - '0' : 0;
			int c2 = n2 >= 0 ? b[n2] - '0' : 0;
			sum = c1 + c2 + carry;
			carry = 0;
			if (sum == 2) {
				sum = 0;
				carry = 1;
			}
			if (sum == 3) {
				sum = 1;
				carry = 1;
			}
			s.push_back(sum + '0');
			n1--;
			n2--;
		}
		if (carry != 0) {
			s.push_back(carry + '0');
		}
		reverse(s.begin(), s.end());
		return s;

	}
};