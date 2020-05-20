//https://www.codechef.com/LRNDSA02/problems/CHFQUEUE
#include <bits/stdc++.h>
#define ll long long int
#define M 1000000007
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	ll n,k;
	cin>>n>>k;
	ll *a=new ll[n];
	for(ll i=0;i<n;i++)
	cin>>a[i];
	stack<pair<ll,ll>>s;
	ll ans=1;
	for(ll i=0;i<n;i++)
	{
		while(!s.empty() && s.top().first>a[i])
		{
			pair<ll,ll>p=s.top();
			ll c=(i-(p.second)+1);
			ans=ans*c;
			ans=ans%M;
			s.pop();
		}
		s.push(make_pair(a[i],i));
	}
	cout<<ans;
	return 0;
}