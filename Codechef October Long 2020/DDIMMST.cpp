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
#define umii			unordered_map<int,int>
#define all(v)			v.begin(),v.end()
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int>>
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define mod             1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)
#define sortall(x)		sort(all(x))
#define deb(x)			cout << #x << "="<< x << '\n'
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());

int power(int , unsigned int);
int ans( vi x, vi y)
{
	int diff = 0;
	for (int i = 0; i < (x.size()); i++)
	{
		diff += abs(x[i] - y[i]);
	}
	return diff;
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
	int n, d;
	cin >> n >> d;
	vector<vi>A(n, vi(d));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < d; j++) {
			cin >> A[i][j];
		}
	}
	vector<vi> graph(n, vi(n, 0));
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			graph[i][j] = ans(A[i], A[j]);
			graph[j][i] = graph[i][j];
		}
	}
	int v = n;
	int parent[n], key[n];
	bool mstSet[n];
	memset(key, -1, sizeof(key));
	memset(mstSet, false, sizeof(mstSet));
	key[0] = 0;
	parent[0] = -1;
	for (int i = 0; i < v - 1; i++) {
		int mx = -1;
		int id = -1;
		for (int x = 0; x < v; x++) {
			if (!mstSet[x] && key[x] > mx)
			{
				mx = key[x];
				id = x;
			}
		}
		mstSet[id] = true;
		int j = 0;
		while (j < v) {
			if (!mstSet[j]) {
				if (graph[id][j] && min(key[j], graph[id][j]) == key[j])
				{
					parent[j] = id;
					key[j] = graph[parent[j]][j];
				}
			}
			j++;
		}
	}
	int sum = 0;
	for (int i = 1; i < v; i++)
	{
		sum += graph[parent[i]][i];
	}
	cout << sum << "\n";

	return 0;
}
int power(int x, unsigned int y)
{
	int res = 1;
	x = x % mod;
	if (x == 0) return 0;
	while (y > 0)
	{
		if (y & 1)
			res = (res * x) % mod;
		y = y >> 1;
		x = (x * x) % mod;
	}
	return res;
}