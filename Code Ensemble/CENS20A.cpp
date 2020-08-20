#include<bits/stdc++.h>
using namespace std;

#define ff              first
#define ss              second
#define int             long long
#define pb              push_back
#define mp              make_pair
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define mod             1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());

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
	int a[n][m], i, j, pre[n][m];
	string s[n];
	for (i = 0; i < n; i++)
		cin >> s[i];

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			a[i][j] = s[i][j] - '0';
			pre[i][j] = 0;
		}
	}
	int q;
	cin >> q;
	int x1, y1, x2, y2;
	while (q--)
	{
		cin >> x1 >> y1 >> x2 >> y2;
		x1--;
		y1--;
		y2--;
		x2--;
		pre[x1][y1]++;
		if (x2 + 1 < n && y2 + 1 < m)
			pre[x2 + 1][y2 + 1]++;
		if (x2 + 1 < n)
			pre[x2 + 1][y1]--;
		if (y2 + 1 < m)
			pre[x1][y2 + 1]--;
	}

	for (i = 0; i < m; i++)
	{
		for (j = 1; j < n; j++)
		{
			pre[j][i] += pre[j - 1][i];
		}
	}

	for (i = 0; i < n; i++)
	{
		for (j = 1; j < m; j++)
		{
			pre[i][j] += pre[i][j - 1];
		}
	}

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			if (pre[i][j] % 2)
			{
				if (a[i][j] == 1)
					cout << 0;
				else
					cout << 1;
			}
			else
				cout << a[i][j];
		}
		cout << "\n";
	}
}