#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
#define lli long long int

int main(){
	int t;
	scanf("%d",&t);
	for(int z=1;z<=t;z++){
		int r,c;
		scanf("%d%d",&r,&c);
		int dance[r][c];
		int square[r][c];
		lli interest = 0;
		for(int i=0;i<r;i++){
			for(int j=0;j<c;j++){
				scanf("%d",&dance[i][j]);
				square[i][j] = dance[i][j];
				interest += (lli)dance[i][j];
			}
		}
		while(true){
			lli tempinterest = 0;
			int eliminated = 0;
			for(int i=0;i<r;i++){
				for(int j=0;j<c;j++){
					int ne = 0;
					int total = 0;
					if(dance[i][j]!=-1){
						for(int x=1;j+x<c;x++){
							if(dance[i][j+x]!=-1){
								total += dance[i][j+x];
								ne++;
								break;
							}
						}
						for(int x=1;j-x>=0;x++){
							if(dance[i][j-x]!=-1){
								total += dance[i][j-x];
								ne++;
								break;
							}
						}
						for(int y=1;i+y<r;y++){
							if(dance[i+y][j]!=-1){
								total += dance[i+y][j];
								ne++;
								break;
							}
						}
						for(int y=1;i-y>=0;y++){
							if(dance[i-y][j]!=-1){
								total += dance[i-y][j];
								ne++;
								break;
							}
						}
						if(ne){
							if(ceil((float)total/(float)ne)>dance[i][j]){
								square[i][j] = -1;
								eliminated++;
							}
							else{
								tempinterest += (lli)dance[i][j];
							}
						}
						else{
							tempinterest += (lli)dance[i][j];
						}
					}
				}
			}
			for(int i=0;i<r;i++){
				for(int j=0;j<c;j++){
					dance[i][j] = square[i][j];
				}
			}
			if(eliminated==0){
				break;
			}
			else{
				interest += tempinterest;
			}
		}
		printf("Case #%d: %d\n",z,interest);
	}
}
