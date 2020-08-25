#include<bits/stdc++.h>
using namespace std;

#define ff              first
#define ss              second
#define int             long long
#define all(x)          x.begin(),x.end()
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
		// Enter code here
		int n, k;
		cin >> n >> k;
		string s;
		cin >> s;
		int ones = 0, zeros = 0;
		for (char i : s)
			if (i == '0')
				zeros++;
			else
				ones++;
		if ((zeros) % (n / k) == 0)
		{
			zeros /= (n / k);
			ones /= (n / k);
			string ans = string(zeros, '0') + string(ones, '1');
			for (int i = 0; i < (n / k); i++)
			{
				cout << ans;
				reverse(all(ans));
			}
			cout << endl;
		}
		else
			cout << "IMPOSSIBLE" << endl;
	}
	return 0;
}