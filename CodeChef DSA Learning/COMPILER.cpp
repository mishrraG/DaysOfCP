https://www.codechef.com/LRNDSA02/submit/COMPILER
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define mod 1000000007
void solve(string &s)
{
    ll i,j=0,x=-1;
    for(i=0;i<s.size();i++)
    {
        
        if(s[i]=='<')
        j++;
        else
        {
            j--;
        }
        if(j<0)
        {
            cout<<i<<endl;
            return;
        }
        if(j==0)
        {
            x=i;
        }
    }
    
    cout<<x+1<<endl;
    return;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll test,i,j,n;
    string s;
    cin>>test;
    while(test--)
    {
        cin>>s;
        solve(s);
    }
	return 0;
}