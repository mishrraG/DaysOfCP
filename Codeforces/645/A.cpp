#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll t;
    cin >> t;
    while(t--){
        ll a,b;
        cin >> a >> b;
        ll  val =((a-1)*b)/2 + ((b-1)/2+1);

        cout << val << '\n';
    }
    return 0;
}