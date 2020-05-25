#include <bits/stdc++.h>
using namespace std;
bool areDistinct(vector<int> arr)
{
    int n = arr.size();
    unordered_set<int> s;
    for (int i = 0; i < n; i++) {
        s.insert(arr[i]);
    }
    return (s.size() == arr.size());
}
bool rep(vector<int>a){
    for(int i=1;i<a.size();++i)
    {
        if(a[i]==a[i-1])
        {
            a.erase(a.begin()+i);
        }
    }
    if(a[a.size()-1]==a[a.size()-2])
        a.erase(a.begin()+a.size()-1);
    return areDistinct(a);
}
bool freq(vector<int>arr,int n){
    unordered_map<int, int> mp;
    unordered_set<int>s;
    int c=0;
    for (int i = 0; i < n; i++)
        mp[arr[i]]++;
    for (int i = 0; i < n; i++) {
        if (mp[arr[i]] != -1)
        {
            s.insert(mp[arr[i]]);
            c++;
            mp[arr[i]] = -1;
        }
    }
    return (s.size() == c);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            a.emplace_back(x);
        }
        if(rep(a) && freq(a,n))
            cout << "YES" << endl;
        else
            cout << "NO" <<endl;
    }
}