
#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        char a[n][n];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
                cin >> a[i][j];
        }
        bool flag = true;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                char c = a[i][j];
                if(c=='1')
                {
                    if(j==n-1 || i==n-1)
                        continue;
                    else if(a[i+1][j]=='1' || a[i][j+1]=='1')
                        continue;
                    else
                    {
                        flag= false;
                        break;
                    }
                }
            }
        }
        if(flag)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}