//https://www.codechef.com/LTIME82B/problems/PRFXGD
#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        string s;
        int k, x, n;
        cin >> s; n = s.size();
        cin >> k >> x;
        int cnt[26];
        memset(cnt, 0, sizeof cnt);
        int ans = 0 ;
        for(int i = 0; i < n ; i++){
            int c = s[i] - 'a';
            if(cnt[c] == x){
                if(k==0) break ;
                k--;
                continue;
            }
            cnt[c]++ ;
            ans++    ;
        }
        cout << ans << "\n";
    }


    return 0 ;
}