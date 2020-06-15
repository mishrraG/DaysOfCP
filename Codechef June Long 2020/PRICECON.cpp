#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tt = 1;
    cin >>tt;
    while(tt--){
        int n,m;
        cin >> n >>m;
        int s=0;
        int s1=0;
        for(int i=0;i<n;i++){
            int x;
            cin >>x;
            s1+=x;
            if(x>m)
                x=m;
            s+=x;
        }
        cout << s1-s <<'\n';
    }
    return 0;
}