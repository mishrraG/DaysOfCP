//https://www.codechef.com/COOK118B/problems/CHEFRECP
#include<bits/stdc++.h>
using namespace std;
void solve(const int * arr,int n)
{
    unordered_map <int,int> mp;
    set<int> s;
    for(int i=0;i<n;i++)
    {
        int x=arr[i];
        int count=0;
        if(mp[x]!=0)
        {
            cout<<"NO"<<endl;
            return ;
        }
        while(i<n && arr[i]==x)
        {
            count++;
            i++;
        }
        i--;
        mp[x]=count;
        s.insert(count);
    }
    int sum=0;
    for(auto i:s)
    {
        sum+=i;
    }
    if(sum==n)
    {
        cout<<"YES"<<endl;
        return;
    }
    cout<<"NO"<<endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        solve(arr,n);
    }
    return 0;
}
