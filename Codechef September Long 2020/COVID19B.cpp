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
		int a[n];
		vector<int> ans;
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		for (int i = 0; i < n; i++)
		{
			int b[n] = {0};
			double meet[n] = {0};
			b[i] = 1;

			for (int j = i; j < n; j++)
			{
				if (a[j] < a[i])
				{
					b[j] = 1;
					meet[j] = double(j - i) / double(a[i] - a[j]);
				}
			}
			for (int j = i; j >= 0; j--)
			{
				if (a[j] > a[i])
				{
					b[j] = 1;
					meet[j] = double(i - j) / double(a[j] - a[i]);
				}
			}
			for (int k = 0; k < n; k++)
			{
				if (b[k] == 1 && k != i)
				{
					for (int x = k + 1; x < n; x++)
					{
						if (a[k] > a[x])
						{
							double temp = double(x - k) / double(a[k] - a[x]);
							if (temp >= meet[k])
							{
								b[x] = 1;
								meet[x] = temp;
							}
						}
					}
					for (int x = k - 1; x >= 0; x--)
					{
						if (a[k] < a[x])
						{
							double temp = double(k - x) / double(a[x] - a[k]);
							if (temp >= meet[k])
							{
								b[x] = 1;
								meet[x] = temp;
							}
						}
					}
				}
			}
			int temp = 0;
			for (int m = 0; m < n; m++)
			{

				if (b[m] == 1)
				{
					temp++;
				}
			}
			ans.push_back(temp);
		}
		sort(ans.begin(), ans.end());
		cout << ans[0] << " " << ans[n - 1] << endl;
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