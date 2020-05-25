#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int c=0;
        if(s.length()%2==0 && s.length()>=4) {
            for (int i = 2; i < s.length(); i += 2) {
                string one = s.substr(0, i);
                string two = s.substr(i,s.length());
                string t11 = one.substr(0, one.length() / 2);
                string t12 = one.substr(one.length() / 2);
                string t21 = two.substr(0, two.length() / 2);
                string t22 = two.substr(two.length() / 2);
                if (t11 == t12 && t21 == t22)
                    c++;
            }
            cout << c << endl;
        } else cout << 0 << endl;
    }
}
