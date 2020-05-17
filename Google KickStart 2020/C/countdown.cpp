#include <bits/stdc++.h>
using namespace std;
/*bool check (const vector<int>&a,int k) {
    for (int i : a){
        if(k!=i)
            return false;
        k--;
    }
    return true;
}*/
int solve(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n ,k;
    cin >> n >> k;
    vector<int>v(n);
    for(int i=0;i<n;i++)
        cin >> v[i];
    int c=0;
    vector<int>fin(k);
    for(int i=0;i<k;i++)
        fin[i]=k-i;
    for(int i=0;i<n-k+1;i++)
    {
        vector<int>temp(k);
        if(v[i]==k) {
            for (int j = 0; j < k; j++) {
                temp[j] = v[i + j];
            }
            if (fin == temp)
                c++;
        }
    }
    return c;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t, i=1;
    cin >> t;
    while(i<=t) {
        cout << "Case #" << i << ": "<<solve() << endl;
        ++i;
    }
    return 0;
}