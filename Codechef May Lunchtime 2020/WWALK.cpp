#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a[n+1];
        int b[n+1];
        for(int i=1;i<=n;i++)
            cin >> a[i];
        for(int i=1;i<=n;i++)
            cin >> b[i];
        a[0]=b[0]=0;
        long long s1 = 0,s2=0;
        long long fin = 0;
        for(int i=0;i<n;i++)
        {
            s1+=a[i];
            s2+=b[i];
            if(s1==s2)
            {
                if(a[i+1]==b[i+1]) {
                    fin += a[i + 1];
                }
            }
        }
        cout << fin << '\n';
    }
    return 0;
}