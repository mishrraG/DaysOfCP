//https://www.codechef.com/LRNDSA03/problems/FENCE
#include <iostream>
#include<utility>
#include<algorithm>
using namespace std;
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
int counti(auto a[], int len)
{
    int cnt=0;
    for(int i=0;i<len-1;i++)
    {
        if(a[i].first==a[i+1].first)
            if(a[i+1].second-a[i].second == 1)
                cnt++;
    }
    return 2*cnt;
}
void solve()
{
    int n,m,k;
    cin>>n>>m>>k;
    int fencecount = k*4;
    int r, c;
    int temp = k;
    pair<int,int> p, rp;
    pair<int,int> arr[k], rarr[k];
    while(temp--)
    {
        cin>>r>>c;
        p.first = r;
        p.second = c;
        rp.first = c;
        rp.second = r;
        arr[temp] = p;
        rarr[temp] = rp;
    }
    sort(arr,arr+k);
    sort(rarr, rarr + k);
    int rcount, dcount;
    rcount = counti(arr,k);
    dcount = counti(rarr,k);
    fencecount -= (rcount+dcount);
    cout<<fencecount<<"\n";
}
int main()
{
    fastio;
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}

