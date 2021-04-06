#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define int long long
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define vi vector<int>
#define mii map<int, int>
#define umii unordered_map<int, int>
#define all(v) v.begin(), v.end()
#define pqb priority_queue<int>
#define pqs priority_queue<int, vi, greater<int>>
#define setbits(x) __builtin_popcountll(x)
#define zrobits(x) __builtin_ctzll(x)
#define mod 1000000007
#define inf 1e18
#define ps(x, y) fixed << setprecision(y) << x
#define mk(arr, n, type) type *arr = new type[n];
#define w(x)  \
	int x;    \
	cin >> x; \
	while (x--)
#define sortall(x) sort(all(x))
#define deb(x) cout << #x << "=" << x << '\n'

int power(int, unsigned int);
int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int a1, a2, a3, a4, a5, a6, a7, a8, a9;
	int a11, a22, a33, a44, a55, a66, a77, a88, a99;
	cin >> a1 >> a2 >> a3;
	cin >> a4 >> a5 >> a6;
	cin >> a7 >> a8 >> a9;
	a11 = a1 + a2 + a4 + 1;
	a22 = a1 + a2 + a3 + a5 + 1;
	a33 = a2 + a6 + a3 + 1;
	a44 = a4 + a1 + a5 + a7 + 1;
	a55 = a2 + a4 + a6 + a8 + a5 + 1;
	a66 = a3 + a5 + a9 + a6 + 1;
	a77 = a7 + a4 + a8 + 1;
	a88 = a8 + a5 + a7 + a9 + 1;
	a99 = a9 + a8 + a6 + 1;
	cout << a11 % 2 << a22 % 2 << a33 % 2 << '\n';
	cout << a44 % 2 << a55 % 2 << a66 % 2 << '\n';
	cout << a77 % 2 << a88 % 2 << a99 % 2 << '\n';

	return 0;
}
int power(int x, unsigned int y)
{
	int res = 1;
	x = x % mod;
	if (x == 0)
		return 0;
	while (y > 0)
	{
		if (y & 1)
			res = (res * x) % mod;
		y = y >> 1;
		x = (x * x) % mod;
	}
	return res;
}