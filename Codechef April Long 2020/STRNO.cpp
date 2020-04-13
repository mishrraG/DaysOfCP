//Question Link : https://www.codechef.com/APRIL20B/problems/STRNO
#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
#define loopf(i,a,b) for(i=a;i<b;i++)
#define loopw(a,b,c) while(a%b==c)

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
	vector<int> a;
		int count = 0;
		int n,i;
		long long int k;
		scanf("%d",&n);
		cin >>k;
		loopw(n,2,0){
		    n/=2;
		    count++;
		}
			if (count)
				a.push_back(count);
		for (long long i = 3; i <= sqrt(n); i += 2){
		    count = 0;
		    loopw(n,i,0) {
		        count++;
		        n /=i;
		    }
		    if (count)
	    	a.push_back(count);	       
		}
		if (n > 2)
			a.push_back(1);
		long long int val=0;
		loopf(i,0,a.size())
		{
			val+=a[i];
		}
		if(val>=k)
			cout<<1<<endl;
		else
			cout<<0<<endl;		
	}
	return 0;
}
