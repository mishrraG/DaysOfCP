/*
Given n non-negative integers representing the histogram's bar height where the
width of each bar is 1, find the area of largest rectangle in the histogram.
*/

class Solution {
public:
	int largestRectangleArea(vector<int>& heights) {
		stack<int>s;
		int maxa = 0;
		int tp = 0;
		int atp = 0;
		int i = 0;
		int n = heights.size();
		while (i < n) {
			if (s.empty() || heights[s.top()] <= heights[i])
				s.push(i++);
			else
			{
				tp = s.top();
				s.pop();


				atp = heights[tp] * (s.empty() ? i : i - s.top() - 1);
				maxa = max(maxa, atp);
			}
		}
		while (s.empty() == false)
		{
			tp = s.top();
			s.pop();
			atp = heights[tp] * (s.empty() ? i : i - s.top() - 1);
			maxa = max(maxa, atp);
		}
		return maxa;
	}
};