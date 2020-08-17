//30 pts sol :/
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
#define pqs             priority_queue<int,vi,greater<int>>
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
		int n;
		cin >> n;
		unordered_map<int, bool> g[n + 1];
		vi p(n + 1), a(n + 1), b(n + 1), d(n + 1, -1);
		p.pb(0);
		for (int i = 1; i < n; i++)
		{
			int u, v;
			cin >> u >> v;
			g[u][v] = g[v][u] = true;
		}
		for (int i = 1; i <= n; i++)
		{
			cin >> p[i];
		}
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i];
		}
		for (int i = 1; i <= n; i++)
		{
			cin >> b[i];
		}
		for (int i = 1; i <= n; i++)
		{
			vector<bool> visited(n + 1, false);
			stack<int> q;
			q.push(p[i]);
			while (!q.empty())
			{
				int src = q.top();
				q.pop();
				if (!visited[src])
				{
					visited[src] = !visited[src];
					b[src] -= min(a[p[i]], b[src]);
					if (!(b[src] > 0) and !(d[src] != -1))
					{
						d[src] = i;
					}
				}
				else
					continue;
				for (auto child : g[src])
				{
					if (child.ss == true && visited[child.ff] == false)
					{
						q.push(child.ff);
					}
				}
			}
			for (auto child : g[p[i]])
			{
				g[p[i]][child.ff] = g[child.ff][p[i]] = false;
			}
		}
		for (int i = 1; i <= n; i++)
		{
			cout << d[i] << " ";
		}
		cout << '\n';
	}
	return 0;
}