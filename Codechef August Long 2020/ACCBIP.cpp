#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define int long long
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define all(x) x.begin(), x.end()
#define vi vector<int>
#define mii map<int, int>
#define pqb priority_queue<int>
#define pqs priority_queue<int, vi, greater<int>>
#define setbits(x) __builtin_popcountll(x)
#define zrobits(x) __builtin_ctzll(x)
#define mod 1000000007
#define inf 1e18
#define ps(x, y) fixed << setprecision(y) << x
#define mk(arr, n, type) type *arr = new type[n];
#define w(x) \
  int x;     \
  cin >> x;  \
  while (x--)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int calc(int num, int colour, vi lines_set[])
{
	vi lines = lines_set[colour];
	for (int i = 0; i < lines.size() && num > 0; i++)
	{
		int tmp = min(lines[i], num);
		lines[i] -= tmp;
		num -= tmp;
	}
	if (num > 0)
		return 0;
	int s1 = 0;
	int tmp[lines.size() + 1];
	for (int i = 0; i < lines.size(); i++) {
		s1 += lines[i];
		tmp[i] = lines[i];
	}
	int s2 = 0;
	for (int i = 0; i < lines.size(); i++)
	{
		s2 += lines[i] * (s1 - lines[i]);
		tmp[i] *= (s1 - lines[i]);
	}
	s2 >>= 1;
	int s3 = 0;
	for (int i = 0; i < lines.size(); i++)
	{
		s3 += lines[i] * (s2 - tmp[i]);
	}
	s3 /= 3;
	return s3;
}
int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	w(t)
	{
		int n, c, k;
		cin >> n >> c >> k;
		mii colour[c + 1];
		vi lines[c + 1];
		for (int i = 1; i <= n; i++)
		{
			int x, y, z;
			cin >> x >> y >> z;
			colour[z][x]++;
		}
		vi v(c + 1, 0);
		for (int i = 1; i <= c; i++)
			cin >> v[i];
		for (int i = 1; i <= c; i++)
		{
			vi ls;
			for (auto it : colour[i])
				ls.emplace_back(it.ss);
			sort(all(ls));
			lines[i] = ls;
		}
		int dp[k + 1][c + 1];
		int mem[k + 1][c + 1];
		for (int i = 0; i <= k; i++)
		{
			for (int j = 0; j <= c; j++)
			{
				dp[i][j] = LLONG_MAX;
				if (!j)
					dp[i][j] = j;
				mem[i][j] = -1;
			}
		}
		for (int i = 0; i <= k; i++)
		{
			for (int j = 1; j <= c; j++)
			{
				int lel = i / v[j];
				for (int k = 0; k <= (lel); k++)
				{
					if (mem[k][j] == -1)
					{
						int x = calc(k, j, lines);
						mem[k][j] = x;
					}
					int b = (dp[i - k * v[j]][j - 1] + mem[k][j]);
					dp[i][j] = min(dp[i][j], b);
				}
			}
		}
		cout << dp[k][c] << '\n';
	}
	return 0;
}