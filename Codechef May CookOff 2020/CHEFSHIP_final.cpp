//https://www.codechef.com/COOK118B/problems/CHEFSHIP
#include <bits/stdc++.h>
using namespace std;
vector < int > Z_function(string &t){
    int L = 0, R = 0;
    vector < int > z(t.size(), 0);
    for(int i = 1; i < (int)t.size(); ++i){
        if(i <= R)z[i] = min(R - i + 1, z[i - L]);
        while(i + z[i] < (int)t.size() && t[z[i]] == t[i + z[i]])z[i]++;
        if(i + z[i] - 1 > R){
            R = i + z[i] - 1;
            L = i;
        }
    }
    reverse(t.begin(), t.end());
    return z;
}
void solve(){
    string t;
    cin >> t;
    vector < int > z1 = Z_function(t);
    vector < int > z2 = Z_function(t);
    int ans = 0;
    for(int i = 1; 2 * (i + 1) <= t.size(); ++i){
        int length1 = i, length2 = ((int)t.size() - 2 * i) / 2;
        if(z1[length1] >= length1 && z2[length2] >= length2){
            ans++;
        }
    }
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 
    cout.tie(nullptr);
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
}