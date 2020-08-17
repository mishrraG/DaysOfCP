#include<bits/stdc++.h>
using namespace std;
#define MAX             256
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

string max(string a, string b) {
	if (a > b)
		return b;
	return a;
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
		string s, p;
		cin >> s >> p;
		vi freqP(26, 0), freqS(26, 0);
		int ctr = 0;
		while (ctr < s.length()) {
			freqS[s[ctr++] - 'a']++;
		}
		ctr = 0;
		while (ctr < p.length()) {
			freqP[p[ctr] - 'a']++;
			freqS[p[ctr++] - 'a']--;
		}
		int pos;
		for (int i = 0; i < 26; i++) {
			if (char(i + 'a') == p[0]) {
				string k1, k2 = "";
				k1 = p;
				int j = 0;
				while (j++ < freqS[i])
					k1 += char(i + 'a');
				while (freqS[i]--)
					k2 += char(i + 'a');
				k2 += p;
				pos = i;
				cout << max(k1, k2);
				break;
			}
			else {
				for (; freqS[i] > 0; freqS[i]--)
					cout << char(i + 'a');
			}
		}
		int x = pos + 1;
		while (x <= 25) {
			int j = 0;
			while (j++ < freqS[x])
			{
				cout << char(x + 'a');
			}
			x++;
		}
		cout << '\n';
	}
}