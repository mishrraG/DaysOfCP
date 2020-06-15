#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        int a,b;
        cin >> a >> b;
        int maximum = max(a,b);
        int minimum = min (a,b);
        if(maximum/2>minimum)
        {
            cout << minimum << '\n';
        } else{
            cout << (a+b)/3 << '\n';
        }
    }
}