#include <bits/stdc++.h>
using namespace std;

int solve(vector<int>& arr, int n) {
 int ans = 0;
 for (int i=0; i<n; i++) {
  int sum = 0;
  for (int j=i; j<n; j++) {
   sum += arr[j];
   double sr = sqrt(sum);
   if (sr - floor(sr) == 0)
    ans++;
  }
 }
 return ans;
}

int main() {
 int t;
 cin >> t;
 int c = 1;
 while (t--) {
  int n, k;
  cin >> n;
  vector<int> arr(n);
  for (int i=0; i<n; i++) {
   cin >> arr[i];
  }
  cout << "Case #" << c++ << ": " << solve(arr, n) << endl;
 }
 return 0;
}