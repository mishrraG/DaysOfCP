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

//Start of program
string goal = "ALLIZZWELL";
int visited[105][105];
int column, row;
vector<string> table;
int check(int r, int c, int a) {

	if (a == 10) return true;
	visited[r][c] = 1;
	for (int i = -1; i <= 1; ++i) {
		for (int j = -1; j <= 1; ++j) {
			int rowS = r + i, colS = c + j;
			if ((i == 0 && j == 0) || rowS < 0 || rowS >= column || colS < 0 || colS >= row || table[rowS][colS] != goal[a])
				continue;
			if (visited[rowS][colS])
				continue;
			if (check(rowS, colS, a + 1)) {
				visited[r][c] = 0;
				return true;
			}
		} // for ends
	} // for ends
	visited[r][c] = 0;
	return false;
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
	string st;
	w(t) {
		table.clear();
		cin >> column >> row;
		for (int i = 0; i < column; ++i) {
			cin >> st;
			table.push_back(st);
		}
		bool res = false;
		for (int i = 0; i < column; ++i)
			for (int j = 0; j < row; ++j)
				if (table[i][j] == 'A' && check(i, j, 1)) {
					res = true; break;
				}

		if (res)    cout << "YES\n";
		else        cout << "NO\n";
	}
	return 0;
}