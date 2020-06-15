#include <iostream>
using namespace std;
#define int long long int
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int c=0;
        for(int i=0;i<s.size()-1;i++)
        {
            if(s[i]!=s[i+1]) {
                c++;
                i+=1;
            }
        }
        cout << c <<'\n';
    }
    return 0;
}
