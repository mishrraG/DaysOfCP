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
int answer[1001][1001];
int help(int start, int end, int f[], int k) {
	if (start == end)
		return k;
	vi fam(101, 0);
	while (start <= end)
		fam[f[start++]]++;
	int size = 100;
	while (size >= 0) {
		if (fam[size] > 1) {
			k += fam[size];
		}
		size--;
	}
	return k;
}
int solve(int start, int end, int f[], int k) {
	if (start > end) {
		return (start < end);
	}
	if (start == end)
		return k ;
	if (answer[start][end])
		return answer[start][end];
	int ans = INT_MAX;
	int itr = start;
	while (itr <= end) {
		ans = min(ans, help(start, itr, f, k) + solve(itr + 1, end, f, k));
		itr++;
	}
	answer[start][end] = ans;
	return ans;
}
void init() {
	memset(answer, 0, sizeof(answer));
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
		init();
		int n, k;
		cin >> n >> k;
		int f[n];
		for (int i = 0; i < n; i++)
			cin >> f[i];
		int ans = k;
		cout << solve(0, n - 1, f, k) << '\n';
	}
	return 0;
}