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
	w(t) {
		int n, m;
		int y = 0, x;
		cin >> n >> m;
		int a[n][m];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++)
			{
				cin >> a[i][j];
				x = 0;
				if (i > 0)
					x++;
				if (i < n - 1)
					x++;
				if (j > 0)
					x++;
				if (j < m - 1)
					x++;
				if (a[i][j] > x)
					y = 1;
				else
					a[i][j] = x;
			}
		}
		if (y == 1)
			cout << "NO\n";
		else
		{
			cout << "YES\n";
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < m; j++)
					cout << a[i][j] << " ";
				cout << "\n";
			}
		}
	}
	return 0;
}