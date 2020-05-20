//https://www.codechef.com/LRNDSA02/problems/ZCO15004
#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    vector <ll> vrr(100003,500);
    vrr[100000]=0;
    ll n,ht,lt,ans=0;
    cin>>n;
    ll i;
    for(i = 0; i < n; i++){
        ll x,y;
        cin>>x>>y;
        if(vrr[x] > y)
            vrr[x] = y;
    }
    stack <ll> st;
    for(i = 1; i <= 100000; i++){
        while(!st.empty() && vrr[st.top()] > vrr[i]){
            ht = vrr[st.top()];
            st.pop();
            lt = 0;
            if(!st.empty())
                lt=st.top();
            ans=max(ans,ht * (i - lt));
        }
        st.push(i);
    }
    cout<<ans<<endl;
}

    
         
    
    