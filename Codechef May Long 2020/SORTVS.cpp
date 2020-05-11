//https://www.codechef.com/MAY20B/problems/SORTVS
#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    long long t,n,m,q,r,flag=0,temp;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        int p[n+1];
        p[0]=INT_MAX;
        for(int i=1;i<=n;i++)
            cin>>p[i];
        int count=0;
        for(int i=1;i<=n-1;i++)
        {
            for(int j=1+i;j<=n;j++)
            {
                if(i==p[j] && p[i]!=p[j])
                {
                    count++;
                    swap(p[i],p[j]);
                    break;
                }
            }
        }
        cout<<count<<endl;
    }
    return 0;
}