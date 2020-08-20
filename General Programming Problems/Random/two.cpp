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

int change(string s)
{
	int n = s.length();
	int cc = 0;
	for (int i = 0; i < n / 2; i++)
	{
		if (s[i] == s[n - i - 1])
			continue;
		cc += 1;
		if (s[i] < s[n - i - 1])
			s[n - i - 1] = s[i];
		else
			s[i] = s[n - i - 1];
	}
	return cc;
}

string ShortestPalindrome(string s)
{
	int n = s.length();

	vector<string> v;
	for (int i = 0; i < n; i++)
	{
		int l = i;
		int r = i;
		string ans1 = "";
		string ans2 = "";
		while (l >= 0 && r < n && s[l] == s[r])
		{
			ans1 += s[l];
			l--;
			r++;
		}
		l = i - 1;
		r = i;
		while (l >= 0 && r < n && s[l] == s[r])
		{
			ans2 += s[l];
			l--;
			r++;
		}
		v.push_back(ans1);
		v.push_back(ans2);
	}
	string ans = v[0];
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i] != "")
		{
			ans = min(ans, v[i]);
		}
	}
	return ans;
}
bool isPalin(string s)
{
	string cp = s;
	reverse(s.begin(), s.end());
	return (cp == s);
}
int val(string s)
{
	if (isPalin(s))
		return 0;
	else {
		int diff = (s.length() - ShortestPalindrome(s).length());
		int chg = change(s);
		return (min((int)(s.length() - ShortestPalindrome(s).length()), change(s)));
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
	w(t) {
		string s;
		cin >> s;
		int n, p;
		cin >> n >> p;
		vector<string> ans;
		vi res;
		for (int i = 0; i < p; i++)
		{
			int a, b;
			cin >> a >> b;
			cout << s.substr(a - 1, b) << '\n';
			res.pb(val(s.substr(a - 1, b)));
		}
		for (int q : res)
			cout << q << ' ';
		cout << '\n';
	}
	return 0;
}