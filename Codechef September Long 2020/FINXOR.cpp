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


bool solve(int n) {
	int ans = 0;
	vi xval(20);
	int x;
	int i = 1;
	while (i <= 20)
	{
		int mk = pow(2, i);
		cout << "1 " << mk << endl;
		int p;
		cin >> p;
		xval.pb(p);
		i++;
	}
	reverse(all(xval));
	int sum = xval[0] - n * (pow(2, 20));
	for (int i = 1; i < 20; i++)
	{
		int mk = (pow(2, 20 - i));
		xval[i] = ((n + (sum - xval[i]) / mk) / 2);
	}
	for (int i = 1; i < xval.size(); i++)
	{
		int mk = (pow(2, 20 - i));
		if (xval[i] & 1)
			ans += mk;
	}
	if (sum & 1)
		ans++;
	cout << "2 " << ans << endl;
	int p;
	cin >> p;
	return (p == 1);

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
	w(t) {
		int n;
		cin >> n;
		if (!solve(n))
			break;
		cout << endl;
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