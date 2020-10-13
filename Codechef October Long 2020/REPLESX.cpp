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
#define umii            unordered_map<int,int>
#define all(v)          v.begin(),v.end()
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int>>
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define mod             1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)
#define sortall(x)      sort(all(x))
#define deb(x)          cout << #x << "="<< x << '\n'
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());

int power(int , unsigned int);
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
		int n, x, p, k;
		cin >> n >> x >> p >> k;
		int e[2] = {0};
		vi a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			if (a[i] < x)
				e[0]++;
			if (a[i] > x)
				e[1]++;
		}
		int res = 0;
		if ((e[0] + 1) > p) {
			if (k <= e[0] && p >= k) {
				res = e[0] - p + 1;
			}
			else
				res = -1;
		}
		else if (e[1] > (n - p)) {
			if ((k + e[1]) > n && k >= p)
			{
				res = e[1] - n + p;
			}
			else
				res = -1;
		}
		cout << res << '\n';
	}
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