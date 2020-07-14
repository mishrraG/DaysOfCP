class Solution {
public:
	double angleClock(int hour, int minutes) {
		return [a = abs((6.0 * (double)minutes) - (30.0 * hour + (double)minutes / 2.0))]() { return min(360.0 - a, a); }();
	}
};