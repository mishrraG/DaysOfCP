//https://www.geeksforgeeks.org/maximum-and-minimum-in-an-array/
#include<bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	int mx = INT_MIN;
	int mn = INT_MAX;
	for (int i = 0; i < n; i++)
	{
		mx = max(a[i], mx);
		mn = min(a[i], mn);
	}
	cout << "Max element= " << mx << "\nMin element= " << mn;
	return 0;
}