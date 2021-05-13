#include<bits/stdc++.h>
using namespace std;
const int mxN = 260;
int dp[mxN][mxN];
int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int n,m;
	cin >> n >> m;
	for(int i=1; i<=n; ++i) {
		for(int j=1; j<=m; ++j) {
			cin >> dp[i][j];
			dp[i][j] += max(dp[i-1][j], dp[i][j-1]);
		}
	}
	cout << dp[n][m] << "\n";
	return 0;
}