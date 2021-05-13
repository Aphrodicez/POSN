#include<bits/stdc++.h>
using namespace std;
const int mxN = 1010;
int dp[mxN][mxN];
char a[mxN], b[mxN];
void query() {
	cin >> (a+1) >> (b+1);
	int n=strlen(a+1), m=strlen(b+1);
	for(int i=1; i<=n; ++i)
		dp[i][0]=i;
	for(int i=1; i<=m; ++i)
		dp[0][i]=i;
	for(int i=1; i<=n; ++i) {
		for(int j=1; j<=m; ++j) {
			if(a[i]==b[j])
				dp[i][j]=dp[i-1][j-1];
			else dp[i][j]=min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]})+1;
		}
	}
	cout << dp[n][m] << "\n";
}
int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int Q;
	cin >> Q;
	while(Q--)
		query();
	return 0;
}
