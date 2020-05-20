// https://www.codechef.com/LRNDSA02/problems/NOTALLFL
#include<bits/stdc++.h>
#include<vector>
using namespace std;
#define fastio ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
#define printclock cerr<<"Time : "<<1000*(ld)clock()/(ld)CLOCKS_PER_SEC<<"ms\n"
#define MAX 1000000
#define mod 1000000007
#define ll long long int
#define ld long double
#define ull unsigned long long
#define li long int
#define str string
#define fr(i,n) for(ll i = 0; i<n; i++)
#define frj(j,i,n) for(ll j = i; j<n; j++)
#define frev(i,n) for(ll i = n-1; i>=0; i--)

int max (int a, int b){
    if (a>b)
        return a;
    return b;
}
int main() {
	
	fastio;
	int t;
	cin>>t;
	
	while (t--){
	    int n, k, flag = 0, ans = 0, count = 0;
	    cin>>n>>k;
	    ll A[n+1], C[k];
	    ll B[k+1];
	    fr (i, n){
	        cin>>A[i];
	    }
	    fr (i, k+1)
	        B[i]=0;
	    fr (i, n){
	       count = i-B[A[i]];
	       B[A[i]]=i+1;
	       ans = max(ans, count);
	    }
	    frj (i, 1, k+1){
	       ans = max(ans, n-B[i]);
	    }
	    cout<<ans<<endl;
	}
	
	return 0;
}
