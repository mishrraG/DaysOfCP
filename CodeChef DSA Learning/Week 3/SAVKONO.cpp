//https://www.codechef.com/LRNDSA03/problems/SAVKONO/
#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
int main()
{
    ios :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin>>t;
    while(t--)
    {
        int n,z;
        cin>>n>>z;
        priority_queue<int> pq;
        int a;
        for(int i=0;i<n;i++)
        {
            cin>>a;
            pq.push(a);
        }
        int ans=0;
        while(!pq.empty() && z>0)
        {
            a=pq.top();
            pq.pop();
            z=z-a;
            a=a/2;
            if(a>0) pq.push(a);
            ans++;
        }
        if(z>0) cout<<"Evacuate\n";
        else cout<<ans<<endl;
    }
}