//https://www.codechef.com/COOK118B/problems/CHEFSHIP
#include <bits/stdc++.h>
#define ll long long
#define MAX 1000000
#define MOD 100000007
using namespace std;
ll hashF[MAX], power[MAX];
ll p=31;
void calculate(string s, int n){
    power[0]=1;
    for(int i=n-1;i>=0;i--){
        hashF[i]=((hashF[i+1]*p)%MOD+(s[i]-'a'+1))%MOD;
        power[n-i]=(power[n-i-1]*p)%MOD;
    }
    power[n]=(power[n-1]*p)%MOD;
}
ll hs(int l,int r){
    return (MOD-(hashF[r+1]*power[r-l+1])%MOD+hashF[l])%MOD;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t = 1;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int n =s.length();
        int count =0;
        calculate(s,n);
        for(int i=2;i<n;i+=2){
            ll t1 =hs(0,i/2-1);
            ll t2 =hs(i/2,i-1);
            ll t3 =hs(i,(n+i)/2-1);
            ll t4 =hs((n+i)/2,n-1);
            if(t1==t2 && t3==t4)
                count++;
        }
        cout << count << "\n";
    }
}