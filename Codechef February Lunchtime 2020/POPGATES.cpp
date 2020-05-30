//https://www.codechef.com/LTIME81B/problems/POPGATES
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        int n, k;
        char c[100];
        cin >> n >> k;
        for(int i=0; i<n; ++i)
            cin >> c[i];
        if(c[n-k]=='H') {
            for(int i=0; i<n; ++i) {
                if(c[i]=='H')
                    c[i]='T';
                else
                    c[i]='H';
            }
        }
        int ans=0;
        for(int i=0; i<n-k; ++i)
            if(c[i]=='H')
                ++ans;
        cout << ans << "\n";
    }
}