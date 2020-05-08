//https://www.codechef.com/LRNDSA02/submit/STUPMACH
#include <iostream>
#define ll long long
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin>>t;
    for(ll i=0;i<t;i++){
        int n,x;
        cin >> n;
        ll min = 1e18;
        ll ans = 0;
        for(ll i=0;i<n;i++){
            cin >> x ;
            if(x<min){
                min = x;
            }
            ans += min;
        }
        cout<<ans<<"\n";
    }
    return 0;
}