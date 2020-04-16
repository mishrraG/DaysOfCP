#include<bits/stdc++.h>
using namespace std;
#define endl "\n"

int main(){
	int t;
	cin>>t;
	for(int z=1;z<=t;z++){
		int n;
		cin>>n;
		vector<string> prefix(n);
		vector<string> suffix(n);
		for(int i=0;i<n;i++){
			string s;
			cin>>s;
			int len = 0;
			for(int j=0;j<s.length();j++){
				if(s[j]=='*'){
					break;
				}
				len++;
			}
			string str = s.substr(0,len);
			prefix[i] = str;
			len = 0;
			for(int j=s.length()-1;j>=0;j--){
				if(s[j]=='*'){
					break;
				}
				len++;
			}
			str = s.substr(s.length()-len,len);
			suffix[i] = str;
		}
		bool flag = true;
		string pre = prefix[0];
		string suf = suffix[0];
		for(int i=1;i<n;i++){
			if(pre.length()<prefix[i].length()){
				for(int j=0;j<pre.length();j++){
					if(pre[j]!=prefix[i][j]){
						flag = false;
						break;
					}
				}
				if(!flag){
					break;
				}
				pre = prefix[i];
			}
			else{
				for(int j=0;j<prefix[i].length();j++){
					if(pre[j]!=prefix[i][j]){
						flag = false;
						break;
					}
				}
				if(!flag){
					break;
				}
			}
			if(suf.length()<suffix[i].length()){
				int l = suf.length();
				int len = suffix[i].length();
				for(int j=0;j<l;j++){
					if(suf[l-j-1]!=suffix[i][len-j-1]){
						flag = false;
						break;
					}
				}
				if(!flag){
					break;
				}
				suf = suffix[i];
			}
			else{
				int l = suf.length();
				int len = suffix[i].length();
				for(int j=0;j<len;j++){
					if(suf[l-j-1]!=suffix[i][len-j-1]){
						flag = false;
						break;
					}
				}
				if(!flag){
					break;
				}
			}
		}
		cout<<"Case #"<<z<<": ";
		if(flag){
			cout<<pre<<suf<<endl;
		}
		else{
			cout<<'*'<<endl;
		}
	}
}