#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
    int n;
    cin>>n;
    vector<int>arr(n);
    int counta=0,countb=0,countc=0;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    for(int i=0; i<n; i++){
        if(arr[i]==5) 
            counta++;
        if(arr[i]==10)
        {
            if(counta>0)
            { 
                counta--; 
                countb++; 
                continue; 
            }
            else
                { 
                cout<<"NO\n"; 
                return;  
                }
        }
        if(arr[i]==15)
        {
            if(countb>0)
            { 
                countb--;
                countc++; 
                continue; 
            }
            if(counta>=2)
            { 
                counta--; 
                counta--; 
                countc++; 
                continue; 
            }
            else
                { 
                cout<<"NO\n"; 
                return;  
                }
        }
    }
    cout<<"YES\n";
}

signed main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}