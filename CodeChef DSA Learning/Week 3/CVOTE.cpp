//https://www.codechef.com/LRNDSA03/problems/CVOTE
#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll n,m;
    cin>>n>>m;
    unordered_map <string, string> cfct;
    unordered_map <string, ll> cf, ct;
    for(ll i=0;i<n;i++)
    {
        string name,country;
        cin>>name>>country;
        cfct.insert({name,country});
    }
    while(m--)
    {
        string email;
        cin>>email;
        cf[email]++;
        ct[cfct[email]]++;
    }
    pair<string, ll> max={"\0",INT_MIN};
    for(auto & i : ct)
    {
        if(i.second>max.second)
        {
            max={i.first,i.second};
        }
        else if(i.second==max.second)
        {
            if(i.first<max.first)
                max={i.first,i.second};
        }
    }
    cout<<max.first<<"\n";
    max={"\0",INT_MIN};
    for(auto & i : cf)
    {
        if(i.second>max.second)
        {
            max=make_pair(i.first,i.second);
        }
        else if(i.second==max.second)
        {
            if(i.first<max.first)
            {
                max=make_pair(i.first,i.second);
            }
        }
    }
    cout<<max.first;
}