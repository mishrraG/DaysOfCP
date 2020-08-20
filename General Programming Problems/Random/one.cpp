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
	int size;
	cin >> size;
	int a[size];
	set<int> s;
	int mxor = 0;
	for (int i = 0; i < size; i++)
	{
		int x;
		cin >> x;
		a[i] = x;
		s.insert(a[i]);
		mxor = mxor | a[i];
	}
	int n = size;
	int p[s.size()];
	int d = 0;
	for (int y : s)
		p[d++] = y;
	vi md;
	for (int i = 0; i < d; i++)
	{
		for (int j = i; j < d; j++)
		{
			int v = 0;
			int w = 0;
			for (int k = i; k <= j; k++)
			{
				v = v | p[k];
				w++;
			}
			if (v == mxor)
				md.pb(j - i + 1);
		}
	}
	int val = *min_element(md.begin(), md.end());
	if (val == n)
		cout << 0;
	else
		cout << val;
	return 0;
}