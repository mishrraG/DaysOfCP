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
bool isPrime(int n)
{
	int c = 0;
	for (int i = 2; i < n; i++)
	{
		if (n % i == 0)
			c++;
	}
	return c == 0;
}
bool isNextPrime(int n, int m)
{
	for (int i = n + 1; i <= m; i++)
	{
		if (isPrime(i))
		{
			if (i == m)
				return true;
			else
				return false;
		}
	}
	return false;
}
int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n, m;
	cin >> n >> m;
	if (isNextPrime(n, m))
		cout << "YES\n";
	else
		cout << "NO\n";
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