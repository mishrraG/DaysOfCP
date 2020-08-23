#include<bits/stdc++.h>
using namespace std;

#define endl			"\n"
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

int solve() {
	int n;
	cin >> n ;
	vi array(n);
	for (int i = 0; i < n; i++)
		cin >> array[i];
	int maxLen = 0;
	for (int i = 0; i < array.size() - 1;)
	{
		int j = i;
		int common_difference = array[i + 1] - array[i];
		while (j < array.size() - 1 && (array[j + 1] - array[j] == common_difference))
			j++;
		int max_j = j;
		maxLen = max(maxLen, max_j - i + 1);
		i = max(i + 1, j);
	}
	return maxLen;
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
	int t;
	cin >> t ;
	for (int i = 1; i <= t; i++) {
		cout << "Case #" << i << ": " << solve() << endl;
	}
	return 0;
}