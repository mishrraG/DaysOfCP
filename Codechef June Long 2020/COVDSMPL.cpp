#include <bits/stdc++.h>
#define MAX 60
using namespace std;
int arr[MAX][MAX];
int x;
int mat(int r1,int c1,int r2,int c2, int count) {
    if (count == 0) {
        for (int i = r1 - 1; i < r2; i++)
            for (int j = c1 - 1; j < c2; j++) {
                arr[i][j] = 0;
            }
        return 0;
    } else if (r1 == r2 && c2 - c1 == count - 1) {
        for (int i = c1 - 1; i < c2; i++) arr[r1 - 1][i] = 1;
        return count;
    } else if (r2 > r1) {
        int dif = (r1 + r2) / 2;
        if (dif - r1 > (r2 - (dif + 1))) {
            cout << "1 " << r1 << " " << c1 << " " << dif << " " << c2 <<endl;
            int under;
            cin >> under;
            if (count == -1)
                return -1;
            int num = mat(r1, c1, dif, c2, under);
            if(num==-1)
                return -1;
            mat(dif+1,c1,r2,c2,count-under);

        } else{
            cout << "1 "<<dif+1<<" "<<c1 <<" "<<r2 << " "<<c2<<endl;
            int under;
            cin >> under;
            if (count == -1)
                return -1;
            int num = mat(dif+1, c1, r2, c2, under);
            if(num==-1)
                return -1;
            mat(r1,c1,dif,c2,count-under);
        }
        return count;

    }
    else
    {
        int dif = (c1+c2)/2;
        if(dif-c1>(c2-(dif+1))){
            cout << "1 " << r1 << " " << c1 << " " << r2 << " " << dif<<endl;
            int under;
            cin >> under;
            if (count == -1)
                return -1;
            int num = mat(r1, c1, r2, dif, under);
            if(num==-1)
                return -1;
            mat(r1,dif+1,r2,c2,count-under);
        } else{
            cout << "1 "<<r1<<" "<<dif+1 <<" "<<r2 << " "<<c2<<endl;
            int under;
            cin >> under;
            if (count == -1)
                return -1;
            int num = mat(r1, dif+1, r2, c2, under);
            if(num==-1)
                return -1;
            mat(r1,c1,r2, dif,count-under);
        }
        return count;
    }
}
int main(){
    int t;
    cin>>t;
    while(t--){
        string st;
        int n,p;
        cin >> n >> p;
        arr[n][n];
        memset(arr,0, sizeof(arr));
        cout <<"1 1 1 "<<n <<" "<<n <<'\n';
        cin >> x;
        if(x==-1)
            break;
        mat(1,1,n,n,x);
        string str;
        str+="2\n";
        for(int i=0;i<n;i++) {
            for (int j = 0; j < n; j++)
                str += to_string(arr[i][j]) + " ";
            str += "\n";
        }
        cout << str;
        cin >> x;
        if(x==1)
            continue;
        else if(x==-1)
            break;
    }
}