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
#define mod 			1000000007
#define mod2 			1000000005
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)
#define sortall(x)		sort(all(x))
#define deb(x)			cout << #x << "="<< x << '\n'
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());

int power(int, int);
int calc(int, int);
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
		int n, ans;
		cin >> n;
		bool chk = false;
		int a[n];
		ans = power(2, n) % mod;
		int mx = INT_MIN;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			mx = max(mx, a[i]);
		}
		int mf = 0;
		for (int i = 0; i < n; i++) {
			if (a[i] == mx)
				mf++;
		}
		if (n == 1)
		{
			cout << "2\n";
			continue;
		}
		if (mf & 1)
			ans = ans % mod;
		else
			ans -= ((power(2, n - mf) % mod) * calc(mf, mf / 2) % mod) % mod;
		if (ans < 0)
			chk = true;
		if (!chk)
			ans = ans % mod;
		else
			ans = ((ans + mod) % mod);
		cout << (ans % mod) << '\n';
	}
	return 0;
}
int power(int x, int y)
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
int calc(int n, int r) {
	int a = 1;
	int tot = ((r < (n - r) ? r : (n - r)));
	for (int i = 0; i < tot; i++)
	{
		a = (a % mod * (n - i) % mod) % mod;
		a = (a % mod * (power(i + 1, mod2) % mod)) % mod;
	}
	return a % mod;
}