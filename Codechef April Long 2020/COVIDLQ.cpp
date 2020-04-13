//Question : https://www.codechef.com/APRIL20B/problems/COVIDLQ 
#include <cstdio>
#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int t;
	scanf("%d",&t);
	while(t--)
	{
	    int n;
	    scanf("%d",&n);
	    string ans="YES";
	    int *arr=new int[n];
	    for(int i=0;i<n;i++)
	    {
	    cin>>arr[i];
	    }

	    int val=0;
			for(int i=0;i<n;i++) {
				if(arr[i]==1) {
					val=(n-i>6)?6:n-i;
					for(int j=1;j<val;j++) {
						if(arr[i+j]==1) {
							ans="NO";
							break;
						}
					}
				}
			}
	    cout<<ans<<endl;
	}
	return 0;
}
