#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        int n ,m;
        cin >> n >> m;
        vector<bool>row(m,false);
        vector<bool>col(n,false);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                char c;
                cin >> c;
                if(c=='1')
                {
                    row[i]=true;
                    col[j]=true;
                }
            }
        }
        int cc=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!row[i]&&!col[j])
                {
                    cc++;
                    row[i]=true;
                    col[j]=true;
                }
            }
        }
        if(cc%2==0)
            cout << "Vivek\n";
        else
            cout << "Ashish\n";
    }
}