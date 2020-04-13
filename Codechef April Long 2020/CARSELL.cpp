//Question Link : https://www.codechef.com/APRIL20B/problems/CARSELL
#include <bits/stdc++.h>
using namespace std;
int main() {
	int t;
	cin>>t;

	while(t--)
	{
	   long long n,sum=0;
	   cin>>n;
	   int *arr=new int[n];
	   for(int i=0;i<n;i++)
	   cin>>arr[i];
	   sort(arr,arr+n,greater<int>());
	   for(int i=0;i<n;i++)
	   {
	       sum+=(arr[i]-i)>0?(arr[i]-i):0;
	       sum=sum%1000000007;
	       }
	   cout<<sum<<"\n";
	}
	return 0;
}
