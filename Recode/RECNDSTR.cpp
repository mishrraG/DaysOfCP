//https://www.codechef.com/submit/RECNDSTR
#include<bits/stdc++.h>
#define loop for (int i = 0; i < n; i++)
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int l = s.length();
        if (l == 1 || l == 2) {
            cout << "YES" << endl;
            continue;
        } else{
            string sl = s.substr(1)+s[0];
            string sr = s[l-1]+s.substr(0,l-1);
            if(sl==sr)
                cout<<"YES"<<endl;
            else
                cout <<"NO"<<endl;
        }
    }
}