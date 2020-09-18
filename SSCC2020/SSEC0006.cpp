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

void simpleSieve(int limit, vector<int> &prime)
{
	bool mark[limit + 1];
	memset(mark, false, sizeof(mark));

	for (int i = 2; i <= limit; ++i)
	{
		if (mark[i] == false)
		{
			prime.push_back(i);
			for (int j = i; j <= limit; j += i)
				mark[j] = true;
		}
	}
}

void primesInRange(int low, int high)
{
	int limit = floor(sqrt(high)) + 1;
	vector<int> prime;
	simpleSieve(limit, prime);
	int n = high - low + 1;
	bool mark[n + 1];
	memset(mark, false, sizeof(mark));
	for (int i = 0; i < prime.size(); i++)
	{
		int loLim = floor(low / prime[i]) * prime[i];
		if (loLim < low)
			loLim += prime[i];
		if (loLim == prime[i])
			loLim += prime[i];
		for (int j = loLim; j <= high; j += prime[i])
			mark[j - low] = true;
	}
	vi lel;
	int ctr=0;
	for (int i = low; i <= high; i++)
		if (!mark[i - low]){
			lel.pb(i);
			ctr++;
		}
	for(int i=0;i<ctr-1;i++)
	{
		
		for(int j=i+1;j<ctr;j++)
		{
			int p = lel[i] * lel[j];
			if (p >= ((low * high) / 4) && p <= (low * high))
			{
				cout << lel[i] << "," << lel[j] << '\n';
			}
			if(p>(low*high))
				break;
		}
	}
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
	int a,b;
	cin >> a >> b;
	primesInRange(a,b);
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