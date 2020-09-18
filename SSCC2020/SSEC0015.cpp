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
	int n;
	cin >> n;
	//n=n*10;
	int mxsum=0;
	pii pos;
	int start=0;
	vi lel;
	int c = 0;
	while (n > 0)
	{
		int p = n % 10;
		lel.pb(p);
		n /= 10;
		c++;
	}
	reverse(all(lel));
	int sum=lel[0];
	for(int i=1;i<lel.size();i++)
	{
		if(lel[i-1]>=lel[i])
		{
			if(mxsum<sum)
			{
				mxsum =sum;
				pos = {start+1,i};
			}
			start = i;
			sum = lel[i];
		}
		else
		{
			sum+=lel[i];
		}
	}
	cout << mxsum << ":" <<pos.first<<"-"<<pos.ss<<"\n";
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