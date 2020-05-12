// https://www.codechef.com/COOK117B/problems/LIFTME
#include <iostream>
using namespace std;
#define ll long long int
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	ll t;
	cin >> t;
	while(t--){
	    ll n,q;
	    cin >> n >> q;
	    ll tot =0;
	    ll curr=0;
	    while (q--){
	        ll a,b;
	        cin>>a>>b;
	        tot +=abs(curr-a) + abs(b-a);
	        curr=b;
	    }
	    cout << tot << endl;
	}
	return 0;
}
