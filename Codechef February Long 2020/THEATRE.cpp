#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

#define ff              first
#define ss              second
#define int            long long
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

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int T,S=0;
    cin>>T;
    while(T--)
    {
        int a[4][4];
        for(int i=0;i<4;i++)
        {
            for(int j=0;j<4;j++)
            {
                a[i][j]=0;
            }
        }
        int n;
        cin>>n;
        char m;
        int t;
        for(int i=0;i<n;i++)
        {
            cin>>m>>t;
            a[int32_t (m)-65][(t/3)-1]++;
        }
        if(n==0)
        {
            cout<<-400<<endl;
            S-=400;
            continue;
        }
        int sum_set[24];
        int sum_set_count=0;
        for(int i=0;i<4;i++)
        {
            int temp_sum_set[4]={0,0,0,0};
            temp_sum_set[0]=a[0][i];
            for(int j=0;j<4;j++)
            {
                if(j==i)
                {
                    continue;
                }
                temp_sum_set[1]=a[1][j];
                for(int k=0;k<4;k++)
                {
                    if(k==i||k==j)
                    {
                        continue;
                    }
                    temp_sum_set[2]=a[2][k];
                    for(int l=0;l<4;l++)
                    {
                        if(l==i||l==j||l==k)
                        {
                            continue;
                        }
                        temp_sum_set[3]=a[3][l];
                        int temp_sum_set2[4];
                        temp_sum_set2[0]=temp_sum_set[0];
                        temp_sum_set2[1]=temp_sum_set[1];
                        temp_sum_set2[2]=temp_sum_set[2];
                        temp_sum_set2[3]=temp_sum_set[3];
                        sort(temp_sum_set2,temp_sum_set2+4);
                        int s=0;
                        for(int o=0;o<4;o++)
                        {
                            if(temp_sum_set2[o]==0)
                            {
                                s-=100;
                            }
                            else
                            {
                                s+=temp_sum_set2[o]*(25*(o+1));
                            }
                        }
                        sum_set[sum_set_count++]=s;
                    }
                }
            }
        }
        sort(sum_set,sum_set+24);
        cout<<sum_set[23]<<endl;
        S+=sum_set[23];
    }
    cout<<S<<endl;
    return  0;
}