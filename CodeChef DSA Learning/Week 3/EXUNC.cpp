#include<bits/stdc++.h>
using namespace std;
const int mod=1e9 + 7;
#define int long long
const int inf=1e18;
const int N=1e6 + 100;
int n, m, arr[N];
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n>>m;
    arr[0]=inf;
    set<int> start;
    for(int i=1;i<=n;i++) {
        cin>>arr[i];
        if(arr[i]%arr[i-1]!=0)
            start.insert(i);
    }
    arr[n+1]=mod;
    while(m--)
    {
        int t;cin>>t;
        if(t==1)
        {
            int ind, val;
            cin>>ind>>val;
            arr[ind]=val;
            if(arr[ind]%arr[ind-1]!=0)
                start.insert(ind);
            else
                start.erase(ind);
            if(arr[ind+1]%arr[ind]!=0)
                start.insert(ind+1);
            else
                start.erase(ind+1);
        }
        else{
            int ind;cin>>ind;
            set<int>::iterator it=start.upper_bound(ind);it--;
            cout<<(*it)<<endl;
        }
    }
}