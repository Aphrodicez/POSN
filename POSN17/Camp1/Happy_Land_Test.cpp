#include <bits/stdc++.h>
using namespace std;
int n,m;
int di[]={-1 ,-1 ,-1 ,0  ,0 ,1 ,1 ,1} ,dj[]={-1 ,0 ,1 ,-1  ,1 ,-1 ,0 ,1};
double ans=1e9,table[5][5];
bool check(int x ,int y){
	return x>=0 and x<n and y>=0 and y<m and table[x][y]!=0;
}
double land(double price ,int cnt){
	if(cnt==n*m){
		ans=min(ans,price);
		return 0;
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(table[i][j]==0) continue;
			for(int k=0;k<8;k++){
				int x=i+di[k] ,y=j+dj[k];
				if(check(x,y)) table[x][y]+=(table[i][j])/10;
			}
			double x=table[i][j];
			table[i][j]=0;
			land(price+x, cnt+1);
			table[i][j]=x;
			for(int k=0;k<8;k++){
				int x=i+di[k] ,y=j+dj[k];
				if(check(x,y)) table[x][y]-=(table[i][j])/10;
			}
		}
	}
	return ;
}
int main(){
	cin>>n>>m;
	for(int i=0;i<n;i++) for(int j=0;j<m;j++) cin>>table[i][j];
	
	land(0 ,0);	
	printf("%.2lf",ans);
	return 0;
}