#include <bits/stdc++.h>
using namespace std;
#define int long long int
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        int a;
        cin >> a;
        if(a<=2)
        {
            cout << "0\n";
        } else if (a%2==1){
            cout << a/2 <<'\n';
        } else if(a%2==0){
            int ct=0;
            while(a>2)
            {
                if(a%2==1)
                {
                    ct+=a/2;
                    break;
                }
                a=a/2;
            }
            cout << ct <<'\n';
        }
    }
    return 0;
}
