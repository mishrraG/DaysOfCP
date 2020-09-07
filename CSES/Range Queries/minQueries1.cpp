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
#define umii            unordered_map<int,int>
#define all(v)          v.begin(),v.end()
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int>>
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define mod             1000000007
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)
#define sortall(x)      sort(all(x))
#define deb(x)          cout << #x << "="<< x << '\n'
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());

constexpr int inf = 1000000000;

struct node
{
    int range_min;

    node()
    {
        range_min = inf;
    }
};

class SegmentTree
{
public:
    SegmentTree(int n) : n_(n)
    {
        tree_.resize(4 * n_);
    }
    ~SegmentTree() = default;

    node range_query(int lQ, int rQ, int l, int r, int pos = 1)
    {
        if (l > rQ || r < lQ || lQ > rQ)
            return node();
        else if (l >= lQ && r <= rQ)
            return tree_[pos];

        int mid = (l + r) / 2;
        node L = range_query(lQ, rQ, l, mid, 2 * pos);
        node R = range_query(lQ, rQ, mid + 1, r, 2 * pos + 1);
        return merge(L, R);
    }

    void point_update(int idx, int val, int l, int r, int pos = 1)
    {
        if (l == r)
        {
            tree_[pos].range_min = val;
            return;
        }
        int mid = (l + r) / 2;
        if (mid >= idx)
            point_update(idx, val, l, mid, 2 * pos);
        else
            point_update(idx, val, mid + 1, r, 2 * pos + 1);
        tree_[pos] = merge(tree_[2 * pos], tree_[2 * pos + 1]);
    }

private:
    node merge(const node &l, const node &r)
    {
        node ret;
        ret.range_min = min(l.range_min, r.range_min);
        return ret;
    }

    vector<node> tree_;
    int n_;
};

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, q;
    cin >> n >> q;
    SegmentTree st(n);
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        st.point_update(i, x, 1, n);
    }
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        cout << st.range_query(l, r, 1, n).range_min << "\n";
    }

    return 0;
}